//
// Author: marvin on 6/10/20.
//

#ifndef SUBSCRIBER_ONE_H
#define SUBSCRIBER_ONE_H

#include "subscriber/subscriber.h"

class Ignacio : public Subscriber {

    void update(float temp, float humidity, float pressure) {
        cout<<"Subscriber Ignacio: \nTemperature -> "<<temp<<"\t\nHumedad -> "<<humidity<<"\t\nPresion -> "<<pressure<<endl;
    }
};



#endif //SUBSCRIBER_ONE_H
