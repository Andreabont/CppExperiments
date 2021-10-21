#include "EventManager.h"

void EventManager::eventRegister(std::string eventName, std::function< void(EventInfo) > callBack) {
    this->callBackList[eventName].push_back(callBack);
}

void EventManager::eventDispatch(std::string eventName){
    EventInfo info;
    info.eventName = eventName;
    for(auto call : this->callBackList[eventName]) {
        call(info);
    }
}
