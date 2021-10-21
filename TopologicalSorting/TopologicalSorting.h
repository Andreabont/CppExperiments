#ifndef TOPSORTING_H
#define TOPSORTING_H

#include <vector>
#include <map>
#include <set>

class DependencyTree {
    
private:
    
    std::map<int, std::set<int>> tree;
    
    void resolver(std::vector<int> &resolved, std::set<int> &unresolved, int item);
    
public:
    
    void insertDependency(int item, int dep);
    
    std::vector<int> getOrder();
    
};

#endif // TOPSORTING_H
