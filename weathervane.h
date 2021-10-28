#ifndef WEATHERVANE_H
#define WEATHERVANE_H
//#pragma once

class WeatherVane {
    public:
        WeatherVane();
        WeatherVane(int windDirection, int windSpeed);
        WeatherVane(const WeatherVane& other) = default;

        int getWindDirection() const;
        void setWindDirection(int value);

        int getWindSpeed() const;
        void setWindSpeed(int value);

        virtual int getType() const { return 1; }
        //virtual int getType() const;
        //virtual void setType();


        ~WeatherVane();

    private:
        int windDirection;
        int windSpeed;
};

#endif // WEATHERVANE_H
