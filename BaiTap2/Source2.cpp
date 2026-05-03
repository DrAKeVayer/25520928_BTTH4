#include "Header2.h"
ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

PhanSo::PhanSo(ll _t, ll _m) : tu(_t), mau(_m) {
	if (_m < 0) {
		mau = -mau;
		tu = -tu;
	}
}

ll PhanSo::getTu() const {
	return tu;
}
ll PhanSo::getMau() const {
	return mau;
}

void PhanSo::RutGon() {
	if (mau < 0) {
		mau = -mau;
		tu = -tu;
	}
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}

PhanSo PhanSo::RutGon(ll tu, ll mau) {
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
	return PhanSo(tu, mau);
}

PhanSo PhanSo::operator+(const PhanSo& b) {
	ll g = gcd(mau, b.getMau());
	ll ntu = tu * (b.getMau() / g) + b.getTu() * (mau / g);
	ll nmau = mau * (b.getMau() / g);
	PhanSo res(ntu, nmau);
	res.RutGon();
	return res;
}

PhanSo PhanSo::operator-(const PhanSo& b) {
	ll g = gcd(mau, b.getMau());
	ll ntu = tu * (b.getMau() / g) - b.getTu() * (mau / g);
	ll nmau = mau * (b.getMau() / g);
	PhanSo res(ntu, nmau);
	res.RutGon();
	return res;
}
PhanSo PhanSo::operator*(const PhanSo& b) {
	ll ntu = tu * b.getTu();
	ll nmau = mau * b.getMau();
	PhanSo res(ntu, nmau);
	res.RutGon();
	return res;
}
PhanSo PhanSo::operator/(const PhanSo& b) {
	ll ntu = tu * b.getMau();
	ll nmau = mau * b.getTu();
	PhanSo res(ntu, nmau);
	res.RutGon();
	return res;
}
bool PhanSo::operator==(const PhanSo& b) {
	ll x = tu * b.getMau();
	ll y = mau * b.getTu();
	return (x == y);
}
bool PhanSo::operator!=(const PhanSo& b) {
	ll x = tu * b.getMau();
	ll y = mau * b.getTu();
	return (x != y);
}
bool PhanSo::operator>(const PhanSo& b) {
	ll x = tu * b.getMau();
	ll y = mau * b.getTu();
	return (x > y);
}
bool PhanSo::operator<(const PhanSo& b) {
	ll x = tu * b.getMau();
	ll y = mau * b.getTu();
	return (x < y);
}
bool PhanSo::operator>=(const PhanSo& b) {
	return !(*this < b);
}
bool PhanSo::operator<=(const PhanSo& b) {
	return !(*this > b);
}
ostream& operator<<(ostream& os, const PhanSo& b) {
	if (b.mau == -1) {
		os << -b.tu;
		return os;
	}
	os << b.tu;
	if (b.mau == 1 || b.tu == 0) return os;
	else os << "/" << b.mau;
	return os;
}
istream& operator>>(istream& is, PhanSo& b) {
	is >> b.tu >> b.mau;
	b.RutGon();
	return is;
}