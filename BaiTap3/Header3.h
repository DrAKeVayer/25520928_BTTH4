#pragma once
#include <iostream>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Time {
protected:
    int gio, phut, giay;
    void Standard(int& h, int& m, int& s);
public:
    Time(int _g = 1, int _p = 1, int _s = 1);
    ~Time() = default;

    int ConvToSec();
    Time ConvToTime(int sec);

    Time& operator++();
    Time& operator--();
    Time operator+(const int& sec);
    Time operator-(const int& sec);
    friend ostream& operator<<(ostream& os, const Time& a);
    friend istream& operator>>(istream& is, Time& a);

    void ShowTime();
};