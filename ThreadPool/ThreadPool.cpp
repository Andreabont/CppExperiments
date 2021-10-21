#include "ThreadPool.h"

#include <iostream>
#include <sstream>

ThreadPool::ThreadPool(int thread_number) : quit_signal(false){

    for(int i = 0; i < thread_number; i++) {
        std::unique_ptr<std::thread> myThread(new std::thread(&ThreadPool::worker, this));
        this->thread_list.push_back(std::move(myThread));
        std::stringstream a;
        a << "[" << this->thread_list.back()->get_id() << "] CREO" << std::endl;
        std::cout << a.str();
    }
    
}

ThreadPool::~ThreadPool() {

    this->quit_signal.store(true);
    this->cvar_signal.notify_all();
    
    for(auto const& i : this->thread_list) {
        std::stringstream a;
        a << "[" << i->get_id() << "] ESCO" << std::endl;
        std::cout << a.str();
        i->join();
    }

}

void ThreadPool::addJob(std::function<void()> job) {
    std::lock_guard<std::mutex> lock(add_lock);
    this->jobs.push(job); // Aggiungo la funzione alla coda
    this->cvar_signal.notify_all(); // Notifico ai thread di eseguirla.
}

void ThreadPool::worker() {

    // Ciclo di esecuzione
    for(;;) {
        
        std::function<void()> func;
        
        // Scope zona critica
        {
            std::unique_lock<std::mutex> lck(this->add_lock);
            
            // Ciclo di attesa
            for(;;) {
                if(this->quit_signal.load()) return; // Segnale uscita
                if(!this->jobs.empty()) break; // Ho qualcosa da eseguire
                this->cvar_signal.wait(lck); // Attendo segnale
            }
            
            // Estraggo funzione da coda
            func = this->jobs.front();
            this->jobs.pop();
           
        }
        
        // Chiamo funzione
        func();
        
    }
    
}
