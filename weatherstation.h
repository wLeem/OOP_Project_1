#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include "weathervane.h"

class WeatherStation: public WeatherVane {
    public:
        WeatherStation();
        WeatherStation(int temperature, int pressure, int windDirection, int windSpeed);
        WeatherStation(const WeatherStation& other) = default;

        int getTemperature() const;
        void setTemperature(int value);

        int getPressure() const;
        void setPressure(int value);

        int getType() const override;

        void operator=(const WeatherStation& WS);

        ~WeatherStation();

    private:
        int temperature;
        int pressure;
};

#endif // WEATHERSTATION_H
