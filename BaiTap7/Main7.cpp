#include "Header7.h"

int main() {
	SetConsoleOutputCP(65001);
	Matrix a;
	cin >> a;
	Matrix b;
	cin >> b;
	cout << '\n' << "Matrix a: ";
	cout << a;
	cout << '\n' << "Matrix b: ";
	cout << b;
	cout << '\n' << "a + b: ";
	cout << a + b;
	cout << '\n' << "a - b: ";
	cout << a - b;
	cout << '\n' << "a * b: ";
	cout << a * b;
	cout << '\n' << "Nhap k: ";
	double k; cin >> k;
	cout << "a * k: ";
	cout << a * k;
	cout << '\n' << "Vector c (col cua a: " << a.getCol() << "): ";
	Vector c;
	cin >> c;
	cout << "a * c: ";
	cout << a * c;
	return 0;
}