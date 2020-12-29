//
// Author: marvin on 6/10/20.
//

#include "weather_data.h"

void WeatherData::register_subscriber(Subscriber* subscriber) {
    subscribers.push_back(subscriber);
}

void WeatherData::remove_subscriber(Subscriber* subscriber) {
    auto it = find(begin(subscribers), end(subscribers), subscriber);
    if (it != subscribers.end())
        subscribers.erase(it);
}

void WeatherData::notify_subscriber() {
    for (Subscriber *s : subscribers)
        s->update(temp, humidity, pressure);
}

void WeatherData::set_state(float _temp, float _humidity, float _pressure) {
    this->temp = _temp;
    this->humidity = _humidity;
    this->pressure = _pressure;
    notify_subscriber();
}


