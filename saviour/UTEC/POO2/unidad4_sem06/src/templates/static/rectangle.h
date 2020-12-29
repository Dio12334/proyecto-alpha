//
// Author: marvin on 5/13/20.
//

#ifndef RECTANGLEST_H
#define RECTANGLEST_H

#include "coord.h"

class RectangleSt {
public:
    void draw() const {
        cout<<"drawing rectangle"<<endl;
    }

    Coord center_of_gravity() const {
        return Coord(15, 6);
    }
};

#endif //RECTANGLEST_H
