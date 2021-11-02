#include "test.h"

#include <iostream>
#include "test.h"
#include <stdbool.h>

using namespace std;

void weatherStationConstructorTest() {
    WeatherStation WeatherStation0;
    WeatherStation WeatherStation1{ 15, 781, 20, 120 };
    assert(WeatherStation1.getTemperature() == 15);
    assert(WeatherStation1.getPressure() == 781);
    WeatherStation WeatherStation2{ WeatherStation1 };
    assert(WeatherStation2.getWindDirection() == WeatherStation1.getWindDirection());
    WeatherStation *WeatherStation3;
    WeatherStation3 = new WeatherStation();
    assert(WeatherStation3 != NULL);
    //delete WeatherStation3;
    std::cerr << "Constructor is working" << std::endl;
}

void weatherStationSetGetTest() {
    WeatherStation WeatherStation0{ 18, 781, 20, 120 };
    WeatherStation0.setTemperature(32);
    assert(WeatherStation0.getTemperature() == 32);
    WeatherStation0.setWindDirection(800);
    assert(WeatherStation0.getWindDirection() != 781);
    std::cerr << "Setter and Getter are working" << std::endl;
}

bool compareWeatherCenter(MeteoCenter& first, MeteoCenter& second) {
    //bool a(true);
    //bool b(false);
    int flag = 0;
    int len = 0;
    if (first.getCountEl() != second.getCountEl()) {
        return false;
    }
    else
        len = first.getSideLength();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            string* strArr1 = first.getWeatherInPoint(i, j);
            string* strArr2 = second.getWeatherInPoint(i, j);
            if (((strArr1[0]) == strArr2[0]) & (strArr1[0] == "1")) {
                if ((strArr1[1] == strArr2[1]) & (strArr1[2] == strArr2[2])) {
                    flag++;
                }
            }
            if (((strArr1[0]) == strArr2[0]) & (strArr1[0] == "2")) {
                if ((strArr1[1] == strArr2[1]) & (strArr1[2] == strArr2[2]) &
                    (strArr1[3] == strArr2[3]) & (strArr1[4] == strArr2[4])) {
                    flag++;
                }
            }
        }
    }
    if (flag == len*len) {
        return true;
    }
    else
        return false;
}

void printMeteoCenter(MeteoCenter& first) {
    int len;
    //int count;
    len = first.getSideLength();
    if (len > 0) {
        int k = 1;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                string* strArr1 = first.getWeatherInPoint(i, j);
                std::cout << " Characteristic of the " << i + j + k << " weather station" << std::endl;
                //std::cout << strArr1[0] << std::endl;
                if (strArr1[0] == "2") {
                    std::cout << " Temperatures: " << strArr1[4] << std::endl;
                    std::cout << " Pressure: " << strArr1[3] << std::endl;
                    std::cout << " Wind speed: " << strArr1[2] << std::endl;
                    std::cout << " Wind direction: " << strArr1[1] << std::endl;
                }
                else {
                    std::cout << " Wind speed: " << strArr1[2] << std::endl;
                    std::cout << " Wind direction: " << strArr1[1] << std::endl;
                }
            }
            k = k + 1;
        }
    }
    else
        std::cout << "The Meteo Center is empty" << std::endl;
}

void meteoCenterConstructorTest() {
    std::cout << std::endl;
    const std::string& pathExport = "D:\\WeatherCenter.txt";
    const std::string& pathImport = "D:\\WeatherCenter.txt";
    int size = 2;
    MeteoCenter MC0(size);
    MeteoCenter MC1(MC0);
    printMeteoCenter(MC0);
    std::cout << std::endl;
    printMeteoCenter(MC1);
    assert(compareWeatherCenter(MC0, MC1)); // Проверяем конструтор копирования
    assert(MC0.getCountEl() == size * size); // Размер коллекции == произведение введенного параметра
    MC0.deleteAll();
    assert(compareWeatherCenter(MC0, MC1) != true); // Проверка копия != оригинал после преобразования
    assert(MC0.getCountEl() == 0); // Размер непустой коллекции после удаления == 0
    //printMeteoCenter(MC1); // Вывести все элементы коллекции
    MC1.exportToFile(pathExport);
    MeteoCenter MC2(size);
    MC2.importFromFile(pathImport);
    assert(compareWeatherCenter(MC1, MC2)); // Метод сравнения коллекций, записанной в файл и прочитанной из коллекции
    std::cout << std::endl;
    std::cerr << "All MeteoCenter's methods are working" << std::endl;
}

void weatherVaneConstructorTest() {
    std::cout << std::endl;
    WeatherVane wv1{10, 12};
    wv1.setWindSpeed(15);
    assert(wv1.getWindSpeed() == 15);
    WeatherVane wv2{wv1};
    assert(wv1.getWindDirection() == wv2.getWindDirection());
    std::cerr << "All WeatherVane's methods are working" << std::endl;
}
