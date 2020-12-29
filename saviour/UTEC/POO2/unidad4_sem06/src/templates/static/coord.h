//
// Author: marvin on 5/13/20.
//

#ifndef COORD_H
#define COORD_H

class Coord {
private:
    long _x;
    long _y;

public:
    Coord(long x, long y) : _x(x), _y(y) {}
    long get_x() {return _x;}
    long get_y() {return _y;}
    void set_x(long x) {_x = x;}
    void set_y(long y) {_y = y;}
};


#endif //COORD_H
