#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class SoPhuc {
protected:
    double thuc;
    double ao;
public:
    SoPhuc(double _t = 1, double _a = 1);

    SoPhuc operator+(const SoPhuc& b);
    SoPhuc operator-(const SoPhuc& b);
    SoPhuc operator*(const SoPhuc& b);
    SoPhuc operator/(const SoPhuc& b);
    friend ostream& operator<<(ostream& os, const SoPhuc& b);
    friend istream& operator>>(istream& is, SoPhuc& b);
    bool operator==(const SoPhuc& b);
    bool operator!=(const SoPhuc& b);

    double getThuc() const;
    double getAo() const;
    ~SoPhuc();
};