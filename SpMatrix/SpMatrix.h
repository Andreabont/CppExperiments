#ifndef SPMATRIX_H
#define SPMATRIX_H

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>

struct Coordinate {
    
    int x,y;
    
    Coordinate(int x1, int y1) {
        x = x1;
        y = y1;
    }

    int getUID() const {
        int times = 10;
        if(y != 0) {
            times = (int)pow(10.0, (double)((int)log10((double)y)) + 1.0);
        }
        return x * times + y;
    }

    
    bool operator< ( const Coordinate &r ) const {
        return getUID() < r.getUID();
    }
    
};

template <typename T, int ZERO = 0>
class SpMatrix {
    
private:
    std::map<Coordinate, T> dataset;
    Coordinate max;
    
public:
    SpMatrix(std::initializer_list<std::vector<T>> list) : max(0,0) {
        int x1 = 0;
        int y1 = 0;
        for(std::vector<T> xVec: list) {
            for(T yVec: xVec) {
                Coordinate mIndex(x1, y1);
                dataset[mIndex] = yVec;
                y1++;
            }
            if (y1 > max.y) max.y = y1;
            y1 = 0;
            x1++;
        }
        max.x = x1;
    }
    
    T at(Coordinate mIndex) {
        if (dataset.find(mIndex) == dataset.end()) {
            return ZERO;
        }
        return dataset[mIndex];
    }
    
    T at(int x1, int y1) {
        Coordinate mIndex(x1, y1);
        return at(mIndex);
    }
    
    std::string getStr() {
        std::stringstream output;
        for(int x1 = 0; x1 < max.x; x1++) {
            for(int y1 = 0; y1 < max.y; y1++) {
                output << at(x1, y1) << " ";
            }
            output << std::endl;
        }
        return output.str();
    }

    inline int getX() {
        return max.x;
    }

    inline int getY(){
        return max.y;
    }
    
};

#endif // SPMATRIX_H
