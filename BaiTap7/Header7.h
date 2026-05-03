#pragma once
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
	double operator[](int i) const;
	void push(double x);
	int getSize() const;
};

class Matrix {
protected:
	int col, row;
	vector<double> mt;
public:
	Matrix(int _c = 0, int _r = 0);
	friend ostream& operator<<(ostream& os, const Matrix& a);
	friend istream& operator>>(istream& is, Matrix& a);
	Matrix operator+(const Matrix& b);
	Matrix operator-(const Matrix& b);
	Matrix operator*(const Matrix& b);
	Matrix operator*(const double& b);
	Vector operator*(const Vector& b);
	int getCol() const;
};