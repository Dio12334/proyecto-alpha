//
// Author: marvin on 6/10/20.
//

#ifndef SUBSCRIBER_THREE_H
#define SUBSCRIBER_THREE_H

#include "subscriber/subscriber.h"

class Alberto : public Subscriber {

    void update(float temp, float humidity, float pressure) override {
        cout<<"Subscriber Alberto: \nTemperature -> "<<temp<<"\t\nHumedad -> "<<humidity<<"\t\nPresion -> "<<pressure<<endl;
    }
};



#endif //SUBSCRIBER_THREE_H
