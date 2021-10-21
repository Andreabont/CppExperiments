#include "TopologicalSorting.h"
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <boost/range/adaptor/map.hpp>

void DependencyTree::insertDependency(int item, int dep) {
        
    tree[item].insert(dep);
        
    if(tree.find(dep) == std::end(tree)) {
        tree[dep];
    }
    
}

void DependencyTree::resolver(std::vector<int>& resolved, std::set<int>& unresolved, int item) {
    
        // Insert item into unresolved set
        unresolved.insert(item);
        
        for(auto &dep : tree[item]) {
            
            if (std::find(std::begin(resolved), std::end(resolved), dep) == std::end(resolved)) {
    
                if (unresolved.find(dep) == std::end(unresolved)) {
                    
                    // Resolve dependencies
                    resolver(resolved, unresolved, dep);
                    
                } else {
                    
                    // Error!
                    std::stringstream error;
                    error << "Found circular dependency! [" << item << " -> " << dep << "]";
                    throw std::runtime_error(error.str());
                    
                }
                
            }
            
        }
                
        // Item resolved!
        if (std::find(std::begin(resolved), std::end(resolved), item) == std::end(resolved)) {
            resolved.push_back(item);
        }
        
        // Remove item from unresolved set
        unresolved.erase(item);
    
}

std::vector<int> DependencyTree::getOrder() {
    
        std::vector<int> resolved = {};
        std::set<int> unresolved = {};

        for(auto &i : boost::adaptors::keys(tree)) {
            resolver(resolved, unresolved, i);
        }
                
        return resolved;
    
}
