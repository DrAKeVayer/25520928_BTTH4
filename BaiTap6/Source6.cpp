#include "Header6.h"

Vector::Vector(int _n) {
	vt.reserve(_n);
}
ostream& operator<<(ostream& os, const Vector& a) {
	if (a.vt.empty()) return os;
	for (int i = 0; i < a.vt.size(); i++) {
		if (a.vt.size() == 1) {
			os << '\n' <<
				"[ " << a.vt[i] << " ]";
		}
		else if (i == 0) {
			os << '\n' <<
				"┌ " << a.vt[i] << " ┐";
		}
		else if (i > 0 && i < a.vt.size() - 1) {
			os << '\n' <<
				"│ " << a.vt[i] << " │";
		}
		if (i == a.vt.size() - 1) {
			os << '\n' <<
				"└ " << a.vt[i] << " ┘";
		}
	}
	return os;
}
istream& operator>>(istream& is, Vector& a) {
	cout << "Size: ";
	int n; is >> n;
	cout << '\n' << "Input: ";
	for (int i = 0; i < n; i++) {
		double x;
		is >> x;
		a.vt.push_back(x);
	}
	return is;
}
Vector Vector::operator+(const Vector& b) {
	if (vt.size() != b.vt.size()) return Vector(0);
	Vector res(vt.size());
	for (int i = 0; i < vt.size(); i++) {
		res.vt.push_back(vt[i] + b.vt[i]);
	}
	return res;
}
Vector Vector::operator-(const Vector& b) {
	if (vt.size() != b.vt.size()) return Vector(0);
	Vector res(vt.size());
	for (int i = 0; i < vt.size(); i++) {
		res.vt.push_back(vt[i] - b.vt[i]);
	}
	return res;
}
double Vector::operator*(const Vector& b) {
	double res = 0;
	if (vt.size() != b.vt.size()) return -37703;
	for (int i = 0; i < vt.size(); i++) {
		res += vt[i] * b.vt[i];
	}
	return res;
}
Vector Vector::operator*(const double& b) {
	if (vt.size() == 0) return Vector(0);
	Vector res(vt.size());
	for (int i = 0; i < vt.size(); i++) {
		res.vt.push_back(vt[i] * b);
	}
	return res;
}
double Vector::size() {
	double res = 0;
	for (int i = 0; i < vt.size(); i++) {
		res += vt[i] * vt[i];
	}
	res = sqrt(res);
	return res;
}
void Vector::normalize() {
	double s = size();
	for (int i = 0; i < vt.size(); i++) {
		vt[i] = vt[i] / s;
	}
}