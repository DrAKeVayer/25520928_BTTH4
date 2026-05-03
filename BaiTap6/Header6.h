#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>
#include <algorithm>

using namespace std;

class Vector {
protected:
	vector<double> vt;
public:
	Vector(int _n = 0);
	friend ostream& operator<<(ostream& os, const Vector& a);
	friend istream& operator>>(istream& is, Vector& a);
	Vector operator+(const Vector& b);
	Vector operator-(const Vector& b);
	double operator*(const Vector& b);
	Vector operator*(const double& b);
	double size();
	void normalize();
};