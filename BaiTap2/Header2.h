#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <windows.h>

using namespace std;

enum SoSanh {
	NHOHON = -1,
	BANG = 0,
	LONHON = 1
};

using ll = long long;

ll gcd(ll a, ll b);

class PhanSo {
protected:
	ll tu = 0;
	ll mau = 0;
public:
	PhanSo(ll _t = 0, ll _m = 1);
	ll getTu() const;
	ll getMau() const;
	void RutGon();
	static PhanSo RutGon(ll tu, ll mau);
	PhanSo operator+(const PhanSo& b);
	PhanSo operator-(const PhanSo& b);
	PhanSo operator*(const PhanSo& b);
	PhanSo operator/(const PhanSo& b);
	bool operator==(const PhanSo& b);
	bool operator!=(const PhanSo& b);
	bool operator>(const PhanSo& b);
	bool operator<(const PhanSo& b);
	bool operator>=(const PhanSo& b);
	bool operator<=(const PhanSo& b);
	friend ostream& operator<<(ostream& os, const PhanSo& b);
	friend istream& operator>>(istream& is, PhanSo& b);
};