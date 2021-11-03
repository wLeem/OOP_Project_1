#ifndef METEOCENTER_H
#define METEOCENTER_H

#include "weatherstation.h"
#include <string>

class MeteoCenter {
    public:
        MeteoCenter(int newSideLentgh);
        MeteoCenter(const MeteoCenter& other);

        //WeatherVane getElement(int a, int b) const;
        void deleteAll();

        int getCountEl() const;
        int getSideLength() const;

        void importFromFile(const std::string path);
        void exportToFile(const std::string path);

        [[nodiscard]] std::string* getWeatherInPoint(int row, int column) const;

        ~MeteoCenter();

    private:
        WeatherVane** matrix;
        int sideLength;
};

#endif // METEOCENTER_H
