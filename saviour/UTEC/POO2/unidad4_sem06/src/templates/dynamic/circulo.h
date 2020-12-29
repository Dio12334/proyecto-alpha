//
// Author: marvin on 5/13/20.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "geoobj.h"

class Circulo : public GeoObj {
public:
    void draw() const override {
        cout<<"drawing circle"<<endl;
    }

    Coord center_of_gravity() const override {
        return Coord(3, 4);
    }
};


#endif //CIRCULO_H
