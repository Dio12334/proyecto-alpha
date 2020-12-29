//
// Author: marvin on 5/13/20.
//

#include "line.h"
#include "rectangle.h"
#include "circulo.h"

template <typename GeoObj>
void draw_static(GeoObj const& obj) {
    obj.draw();
}

template <typename GeoObj1, typename GeoObj2>
double distance_static(GeoObj1 const& obj1, GeoObj2 const& obj2) {
    Coord c1 = obj1.center_of_gravity();
    Coord c2 = obj2.center_of_gravity();
    double res = sqrt(pow(c1.get_x() - c2.get_x(), 2) + pow(c1.get_y() - c2.get_y(), 2));
    return res;
}

template <typename GeoObj>
void draw_elems_static(vector<GeoObj> const& elems) {
    for (unsigned i = 0; i < elems.size(); i++)
        elems[i].draw();
}
