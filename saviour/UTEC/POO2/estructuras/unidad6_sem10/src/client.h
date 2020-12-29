//
// Author: marvin on 6/10/20.
//

#ifndef CLIENT_H
#define CLIENT_H

#include "subscriber/subscriber.h"

class GeneralSubscriber : public Subscriber {
private:
    int id;

    void update(float temp, float humidity, float pressure) {
        cout<<"Subscriber General: \nTemperature -> "<<temp<<"\t\nHumedad -> "<<humidity<<"\t\nPresion -> "<<pressure<<endl;
    }

public:
    GeneralSubscriber(int _id) : id(_id) {}
};



#endif //CLIENT_H
