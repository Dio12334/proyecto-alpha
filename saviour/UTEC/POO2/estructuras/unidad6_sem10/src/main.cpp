//
// Author: marvin on 6/10/20.
//

#include "weather_data.h"
#include "subscriber_one.h"
#include "subscriber_two.h"
#include "subscriber_three.h"

#include "client.h"

int main() {
    WeatherData weatherData;
    Ignacio ignacio;
    Daniela daniela;
    Alberto alberto;

    GeneralSubscriber s1(1), s2(2), s3(3), s4(4);

    weatherData.register_subscriber(&s1);

    float temp, humidity, pressure;
    weatherData.register_subscriber(&ignacio);
    weatherData.register_subscriber(&daniela);
    weatherData.register_subscriber(&alberto);

    cout<<"WeatherStation: Enter temperature, humidity, pressure (Separate by spaces): ";
    cin>>temp>>humidity>>pressure;

    weatherData.set_state(temp, humidity, pressure);

    weatherData.remove_subscriber(&daniela);

    cout<<"WeatherStation: Enter temperature, humidity, pressure (Separate by spaces): ";
    cin>>temp>>humidity>>pressure;

    weatherData.set_state(temp, humidity, pressure);

    return 0;
}
