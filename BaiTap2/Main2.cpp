#include "Header2.h"

int main() {
	SetConsoleOutputCP(65001);
	PhanSo a, b;
	cout << "Nhap 2 phan so: ";
	cin >> a >> b;
	cout << '\n' << "a + b = ";
	cout << a + b;
	cout << '\n' << "a - b = ";
	cout << a - b;
	cout << '\n' << "a * b = ";
	cout << a * b;
	cout << '\n' << "a / b = ";
	cout << a / b;
	cout << '\n' << "a == b: ";
	if (a == b) cout << "Yes!";
	else if (a != b) cout << "Nope!";
	cout << '\n' << "a > b: ";
	if (a > b) cout << "Yes!";
	else if (a <= b) cout << "Nope!";
	cout << '\n' << "a < b: ";
	if (a < b) cout << "Yes!";
	else if (a >= b) cout << "Nope!";
	return 0;
}