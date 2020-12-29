//
// Author: marvin on 5/13/20.
//

#include "line.h"
#include "rectangle.h"
#include "circulo.h"

void my_draw(GeoObj const& obj) {
    obj.draw();
}

double distance(GeoObj const& obj1, GeoObj const& obj2) {
    Coord c1 = obj1.center_of_gravity();
    Coord c2 = obj2.center_of_gravity();
    double res = sqrt(pow(c1.get_x() - c2.get_x(), 2) + pow(c1.get_y() - c2.get_y(), 2));
    return res;
}

void draw_elems(vector<GeoObj*> const& elems) {
    for (size_t i = 0; i < elems.size(); i++)
        elems[i]->draw();

}
