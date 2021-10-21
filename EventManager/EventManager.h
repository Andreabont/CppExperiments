#ifndef EMAN_H
#define EMAN_H

#include <string>
#include <functional>
#include <map>
#include <list>

struct EventInfo {
  
    std::string eventName;
    
};

class EventManager {
    
private:
    std::map<std::string, std::list<std::function<void(EventInfo)>>> callBackList;
    
public:
    void eventRegister(std::string eventName, std::function<void(EventInfo)> callBack);
    void eventDispatch(std::string eventName);
    
};

#endif // EMAN_H
