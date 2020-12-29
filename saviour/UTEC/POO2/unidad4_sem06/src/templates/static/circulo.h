//
// Author: marvin on 5/13/20.
//

#ifndef CIRCULOST_H
#define CIRCULOST_H

#include "coord.h"

class CirculoSt {
public:
    void draw() const {
        cout<<"drawing circle"<<endl;
    }

    Coord center_of_gravity() const {
        return Coord(3, 4);
    }
};


#endif //CIRCULOST_H
