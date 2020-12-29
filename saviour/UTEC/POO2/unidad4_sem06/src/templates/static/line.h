//
// Author: marvin on 5/13/20.
//

#ifndef LINEST_H
#define LINEST_H

#include "coord.h"

class LineSt {
public:
    void draw() const {
        cout<<"drawing line"<<endl;
    }

    Coord center_of_gravity() const {
        return Coord(10, 7);
    }
};

#endif //LINEST_H
