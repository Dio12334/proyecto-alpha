//
// Author: marvin on 5/13/20.
//

#ifndef LINE_H
#define LINE_H

#include "geoobj.h"

class Line : public GeoObj {
public:
    void draw() const override {
        cout<<"drawing line"<<endl;
    }

    Coord center_of_gravity() const override {
        return Coord(10, 7);
    }
};

#endif //LINE_H
