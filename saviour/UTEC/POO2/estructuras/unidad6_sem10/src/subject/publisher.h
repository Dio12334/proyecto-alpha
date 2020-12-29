//
// Author: marvin on 6/10/20.
//

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "../subscriber/subscriber.h"

class Publisher {
public:
    virtual void register_subscriber(Subscriber* subscriber) = 0;
    virtual void remove_subscriber(Subscriber* subscriber) = 0;
    virtual void notify_subscriber() = 0;
};



#endif //PUBLISHER_H
