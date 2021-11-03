#include "meteocenter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

MeteoCenter::MeteoCenter(int newSideLentgh) {
    //srand(time(NULL));
    int _type = 0;
    this->sideLength = newSideLentgh;
    this->matrix = new WeatherVane *[sideLength];
    for (int i = 0; i < sideLength; i++) {
        matrix[i] = new WeatherVane [sideLength];
        for (int j = 0; j < sideLength; j++) {
            _type = 1 + rand() % 2;
            if (_type == 1) {
                matrix[i][j] = WeatherVane();
                matrix[i][j].setWindDirection(0 + rand() % 12);
                matrix[i][j].setWindSpeed(0 + rand() % 50);
            }
            else {
                WeatherStation t = WeatherStation();
                t.setPressure(568 + rand() % 651);
                t.setTemperature(-50 + rand() % 50);
                t.setWindDirection(0 + rand() % 12);
                t.setWindSpeed(0 + rand() % 50);
                matrix[i][j] = t;
            }
        }
    }
}

MeteoCenter::MeteoCenter(const MeteoCenter& other) {
    //this->count = other.getCountEl();
    this->sideLength = other.sideLength;
    this->matrix = new WeatherVane *[sideLength];
    for (int i = 0; i < sideLength; i++) {
        this->matrix[i] = new WeatherVane [sideLength];
        for (int j = 0; j < sideLength; j++) {
            if (other.matrix[i][j].getType() == 1) {
                this->matrix[i][j] = WeatherVane(other.matrix[i][j]);
            }
            else {
                WeatherStation prom = (WeatherStation&)other.matrix[i][j];
                this->matrix[i][j] = WeatherStation(prom);
            }
        }
    }
}

string* MeteoCenter::getWeatherInPoint(int row, int column) const {

    string* arr = new string[5];
    if ((column+row) % 2 == 0){
        int _type = matrix[row][column].getType();
        arr[0] = to_string(_type);
        float _wd = matrix[row][column].getWindDirection();
        arr[1] = to_string(_wd);
        float _wv = matrix[row][column].getWindSpeed();
        arr[2] = to_string(_wv);
        arr[3] = "0";
        arr[4] = "0";
    }
    else {
        WeatherStation y = (WeatherStation&)matrix[row][column];
        int _type = y.getType();
        arr[0] = to_string(_type);
        float _wd = y.getWindDirection();
        arr[1] = to_string(_wd);
        float _wv = y.getWindSpeed();
        arr[2] = to_string(_wv);
        float _pres = 761 - row;
        arr[3] = to_string(_pres);
        float _temp = 10 + column + row;
        arr[4] = to_string(_temp);

    }
    return arr;
}

void MeteoCenter::deleteAll() {
    for (int i = 0; i < sideLength; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    sideLength = 0;
}

int MeteoCenter::getCountEl() const {
    int count = 0;
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) {
            count++;
        }
    }
    return count;
}

int MeteoCenter::getSideLength() const {
    return sideLength;
}

void MeteoCenter::importFromFile(const string path) {
    std::ifstream file;
    int typeW;
    float temp;
    float pres;
    float windVel;
    float windDir;
    delete matrix;

    file.open(path);
    if (file.is_open()) {
        file >> this->sideLength;
        this->matrix = new WeatherVane *[sideLength];
        for (int i = 0; i < sideLength && !file.eof(); i++) {
            this->matrix[i] = new WeatherVane [sideLength];
            for (int j = 0; j < sideLength && !file.eof(); j++) {
                file >> typeW;
                if (typeW == 1) {
                    file >> windVel;
                    file >> windDir;
                    this->matrix[i][j] = WeatherVane(windDir, windVel);
                }
                else {
                    file >> temp;
                    file >> pres;
                    file >> windVel;
                    file >> windDir;
                    this->matrix[i][j] = WeatherStation(temp, pres, windDir, windVel);
                }

            }
        }
    }
    file.close();
}

void MeteoCenter::exportToFile(const string path) {
    std::ofstream file;
    file.open(path);
    if (file.is_open()) {
        file << sideLength << std::endl;
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                if (matrix[i][j].getType() == 1) {
                    file << matrix[i][j].getType() << std::endl;
                    file << matrix[i][j].getWindSpeed() << std::endl;
                    file << matrix[i][j].getWindDirection() << std::endl;
                }
                else {
                    WeatherStation itr = (WeatherStation&)matrix[i][j];
                    file << itr.getType() << std::endl;
                    file << itr.getTemperature() << std::endl;
                    file << itr.getPressure() << std::endl;
                    file << itr.getWindSpeed() << std::endl;
                    file << itr.getWindDirection() << std::endl;
                }

            }
        }
    }
    else {
        std::cout << "Export file NOT opened!" << std::endl;
    }
    file.close();
}


MeteoCenter::~MeteoCenter() {
    if (sideLength != 0) {
        for (int i = 0; i < sideLength; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}


