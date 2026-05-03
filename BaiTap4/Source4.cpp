#include "Header4.h"
void Date::InitLimit() {
	limit[2] = ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) ? 29 : 28;
}

Date::Date(int _d, int _m, int _y) : ngay(_d), thang(_m), nam(_y) {
	InitLimit();
}

int Date::ConvToDay() {
	int day = (nam - 1) * 365;
	for (int i = 1; i < thang; i++) {
		day += limit[i];
	}
	day += ngay;
	day += (nam - 1) / 4 - (nam - 1) / 100 + (nam - 1) / 400;
	return day;
}

Date& Date::operator++() {
	ngay++;
	if (ngay > limit[thang]) {
		thang++;
		ngay = 1;
	}
	if (thang > 12) {
		thang = 1;
		nam++;
	}
	return *this;
}
Date& Date::operator--() {
	ngay--;
	if (ngay < 1) {
		thang--;
		ngay = limit[thang];
	}
	if (thang < 1) {
		thang = 12;
		nam--;
	}
	return *this;
}
Date Date::operator+(const int& Ngay) {
	ngay += Ngay;
	while (ngay > limit[thang]) {
		ngay -= limit[thang];
		thang++;
		if (thang > 12) {
			nam++;
			thang = 1;
			InitLimit();
		}
	}
	return *this;
}
Date Date::operator-(const int& Ngay) {
	ngay -= Ngay;
	while (ngay < 1) {
		thang--;
		if (thang < 1) {
			nam--;
			thang = 12;
			InitLimit();
		}
		ngay += limit[thang];
	}
	return *this;
}
int Date::operator-(Date& other) {
	return abs(ConvToDay() - other.ConvToDay());
}
bool Date::operator==(const Date& other) {
	return (nam == other.getY() && thang == other.getM() && ngay == other.getD());
}
bool Date::operator!=(const Date& other) {
	return (nam != other.getY() || thang != other.getM() || ngay != other.getD());
}
ostream& operator<<(ostream& os, const Date& a) {
	os << setfill('0') << "[" << setw(2) << a.ngay << "/" << setw(2) << a.thang << "/" << setw(2) << a.nam << "]";
	return os;
}
istream& operator>>(istream& is, Date& a) {
	is >> a.ngay >> a.thang >> a.nam;
	a.InitLimit();
	return is;
}

long double Date::LaiKep(Date& a, Date& b, int Goc, double Lai) {
	long double res;
	res = Goc * powl((1.0 + (Lai / 100.0) / 365.0), b - a);
	return res;
}

int Date::getY() const {
	return nam;
}
int Date::getM() const {
	return thang;
}
int Date::getD() const {
	return ngay;
}