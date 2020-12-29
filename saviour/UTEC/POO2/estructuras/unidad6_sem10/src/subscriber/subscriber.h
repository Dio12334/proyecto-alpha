//
// Author: marvin on 6/10/20.
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber {
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};


#endif //SUBSCRIBER_H
