#include "weathervane.h"
#include <iostream>


WeatherVane::WeatherVane() {
    windDirection = 0;
    windSpeed = 0;
}

WeatherVane::WeatherVane(int windDir, int windSp) {
    windDirection = windDir;
    windSpeed = windSp;
}

int WeatherVane::getWindDirection() const {
    return windDirection;
}
void WeatherVane::setWindDirection(const int x) {
    windDirection = x;
}

int WeatherVane::getWindSpeed() const {
    return windSpeed;
}
void WeatherVane::setWindSpeed(const int x) {
    windSpeed = x;
}

/*int WeatherVane::getType() const {
    return typeW;
}*/

/*WeatherStation WeatherVane::setType(int t){
    WeatherStation ws;
    return ws;
}*/

WeatherVane::~WeatherVane() {
    //std::cout << "Delete " << typeid(this).name() << std::endl;
}
