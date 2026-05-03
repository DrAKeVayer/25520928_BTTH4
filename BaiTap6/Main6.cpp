#include "Header6.h"

int main() {
	SetConsoleOutputCP(65001);
	Vector a;
	cin >> a;
	Vector b;
	cin >> b;
	cout << '\n' << "Vector a: ";
	cout << a;
	cout << '\n' << "Vector b: ";
	cout << b;
	cout << '\n' << "a + b: ";
	cout << a + b;
	cout << '\n' << "a - b: ";
	cout << a - b;
	cout << '\n' << "a * b (tich vo huong): ";
	cout << a * b;
	cout << '\n' << "Nhap k: ";
	double k; cin >> k;
	cout << "a * k: ";
	cout << a * k;
	cout << '\n' << "Do dai vector a: ";
	cout << a.size();
	cout << '\n' << "Chuan hoa vector a: ";
	a.normalize();
	cout << a;
	return 0;
}