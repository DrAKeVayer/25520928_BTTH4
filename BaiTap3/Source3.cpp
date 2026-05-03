#include "Header3.h"
Time::Time(int _g, int _p, int _s) : gio(_g), phut(_p), giay(_s) {
	Standard(gio, phut, giay);
}

void Time::Standard(int& h, int& m, int& s) {
	int sec = 0;
	sec = s + m * 60 + h * 3600;
	while (sec < 0) sec += 86400;
	sec = sec % 86400;
	h = sec / 3600;
	sec %= 3600;
	m = sec / 60;
	sec %= 60;
	s = sec;
}

int Time::ConvToSec() {
	int sec = 0;
	sec = giay + phut * 60 + gio * 3600;
	return sec;
}
Time Time::ConvToTime(int Sec) {
	while (Sec < 0) Sec += 86400;
	int sec = Sec % 86400;
	int gio = sec / 3600;
	sec %= 3600;
	int phut = sec / 60;
	sec %= 60;
	return Time(gio, phut, sec);
}

Time& Time::operator++() {
	giay++;
	*this = ConvToTime(ConvToSec());
	return *this;
}
Time& Time::operator--() {
	giay--;
	*this = ConvToTime(ConvToSec());
	return *this;
}
Time Time::operator+(const int& sec) {
	giay += sec;
	*this = ConvToTime(ConvToSec());
	return *this;
}
Time Time::operator-(const int& sec) {
	giay -= sec;
	*this = ConvToTime(ConvToSec());
	return *this;
}
ostream& operator<<(ostream& os, const Time& a) {
	os << setfill('0') << "[" << setw(2) << a.gio << ":" << setw(2) << a.phut << ":" << setw(2) << a.giay << "]";
	return os;
}
istream& operator>>(istream& is, Time& a) {
	is >> a.gio >> a.phut >> a.giay;
	a.Standard(a.gio, a.phut, a.giay);
	return is;
}

void Time::ShowTime() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	COORD oldPos = csbi.dwCursorPosition;
	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	stringstream ss;
	ss << "[" << (gio < 10 ? "0" : "") << gio << ":"
		<< (phut < 10 ? "0" : "") << phut << ":"
		<< (giay < 10 ? "0" : "") << giay << "]";
	string s = ss.str();

	COORD clockPos = { (SHORT)(width - (SHORT)s.length()), 0 };
	SetConsoleCursorPosition(hConsole, clockPos);
	cout << s;

	SetConsoleCursorPosition(hConsole, oldPos);
}