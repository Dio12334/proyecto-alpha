//
// Author: marvin on 6/10/20.
//

#ifndef SUBSCRIBER_TWO_H
#define SUBSCRIBER_TWO_H

#include "subscriber/subscriber.h"

class Daniela : public Subscriber {

    void update(float temp, float humidity, float pressure) {
        cout<<"Subscriber Daniela: \nTemperature -> "<<temp<<"\t\nHumedad -> "<<humidity<<"\t\nPresion -> "<<pressure<<endl;
    }
};



#endif //SUBSCRIBER_TWO_H
