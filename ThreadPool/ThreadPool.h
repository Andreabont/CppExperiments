#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <functional>
#include <condition_variable>
#include <atomic>
#include <list>
#include <queue>
#include <mutex>
#include <memory>

class ThreadPool {
    
private:
    std::queue<std::function<void()>> jobs;
    std::list<std::unique_ptr<std::thread>> thread_list;
    std::atomic<bool> quit_signal;
    std::mutex add_lock;
    std::condition_variable cvar_signal;
    void worker();
    
public:
    ThreadPool(int thread_number);
    ~ThreadPool();
    void addJob(std::function<void()> job);
    
};

#endif // THREADPOOL_H
