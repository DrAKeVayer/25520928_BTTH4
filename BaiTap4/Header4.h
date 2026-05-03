#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

class Date {
protected:
    int ngay, thang, nam;
    int limit[13] = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    Date(int _g = 1, int _p = 1, int _s = 1);
    ~Date() = default;

    int ConvToDay();

    Date& operator++();
    Date& operator--();
    Date operator+(const int& Ngay);
    Date operator-(const int& Ngay);
    int operator-(Date& other);
    bool operator==(const Date& other);
    bool operator!=(const Date& other);
    friend ostream& operator<<(ostream& os, const Date& a);
    friend istream& operator>>(istream& is, Date& a);
    long double LaiKep(Date& a, Date& b, int Goc, double Lai);
    void InitLimit();

    int getY() const;
    int getM() const;
    int getD() const;
};