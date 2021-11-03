#include "weatherstation.h"

#include "weatherstation.h"
#include <iostream>

WeatherStation::WeatherStation(){
    temperature = 0;
    pressure = 0;
}

WeatherStation::WeatherStation(int temp, int press, int windDir, int windSp) :
    WeatherVane(windDir, windSp), temperature(temp), pressure(press) {}


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

int WeatherStation::getType() const {
    return 2;
}

void WeatherStation::operator=(const WeatherStation& WS) {
    this->temperature = WS.temperature;
    this->pressure = WS.pressure;
    this->setWindDirection(WS.getWindDirection());
    this->setWindSpeed(WS.getWindSpeed());
}

WeatherStation::~WeatherStation() {
    //std::cout << "Delete " << typeid(this).name() << std::endl;
}
