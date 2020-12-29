//
// Author: marvin on 6/10/20.
//

#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include "subject/publisher.h"
#include "lib.h"
class WeatherData : public Publisher {
private:
    vector<Subscriber*> subscribers;
    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

public:
    void register_subscriber(Subscriber* subscriber) override;
    void remove_subscriber(Subscriber* subscriber) override;
    void notify_subscriber() override;

    void set_state(float _temp, float _humidity, float _pressure);
};

#endif //WEATHER_DATA_H
