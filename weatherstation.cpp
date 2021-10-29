#include "weatherstation.h"

#include "weatherstation.h"
#include <iostream>

WeatherStation::WeatherStation(){
    //WeatherVane();
    //WeatherVane(0, 0);
    temperature = 0;
    pressure = 0;
    //windDirection = 0;
    //windSpeed = 0;
}

WeatherStation::WeatherStation(int temp, int press, int windDir, int windSp) :
    WeatherVane(windDir, windSp), temperature(temp), pressure(press) {}
    //windDirection = windDir;
    //windSpeed = windSp;


int WeatherStation::getTemperature() const {
    return temperature;
}
void WeatherStation::setTemperature(const int x) {
    temperature = x;
}

int WeatherStation::getPressure() const {
    return pressure;
}
void WeatherStation::setPressure(const int x) {
    pressure = x;
}

/*int WeatherStation::getWindDirection() const {
    return windDirection;
}
void WeatherStation::setWindDirection(const int x) {
    windDirection = x;
}

int WeatherStation::getWindSpeed() const {
    return windSpeed;
}
void WeatherStation::setWindSpeed(const int x) {
    windSpeed = x;
}*/

int WeatherStation::getType() const {
    return 2;
}

/*void WeatherStation::setType() {
    typeW = 2;
}*/

void WeatherStation::operator=(const WeatherStation& WS) {
    this->temperature = WS.temperature;
    this->pressure = WS.pressure;
    this->setWindDirection(WS.getWindDirection());
    this->setWindSpeed(WS.getWindSpeed());
}

WeatherStation::~WeatherStation() {
    //std::cout << "Delete " << typeid(this).name() << std::endl;
}
