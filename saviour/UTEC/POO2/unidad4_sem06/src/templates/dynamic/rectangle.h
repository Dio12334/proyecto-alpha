//
// Author: marvin on 5/13/20.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geoobj.h"

class Rectangle : public GeoObj {
public:
    void draw() const override {
        cout<<"drawing rectangle"<<endl;
    }

    Coord center_of_gravity() const override {
        return Coord(15, 6);
    }
};

#endif //RECTANGLE_H
