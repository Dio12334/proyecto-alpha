//
// Author: marvin on 5/13/20.
//

#ifndef GEOOBJ_H
#define GEOOBJ_H

#include "../../lib.h"
#include "coord.h"


class GeoObj {
public:
    virtual void draw() const = 0;
    virtual Coord center_of_gravity() const = 0;
    virtual ~GeoObj() = default;
};


#endif //GEOOBJ_H
