#include "Header4.h"

int main() {
	cout << "Nhap Date 1: ";
	Date d;
	cin >> d;
	cout << d;
	++d;
	cout << '\n' << d;
	--d;
	cout << '\n' << d;
	cout << '\n' << "Nhap so ngay cong them: ";
	int x; cin >> x;
	d = d + x;
	cout << d;
	cout << '\n' << "Nhap so ngay tru di: ";
	cin >> x;
	d = d - x;
	cout << d;
	Date e;
	cout << '\n' << "Nhap Date 2 (date rut tien): ";
	cin >> e;
	cout << "Khoang cach giua 2 Date: ";
	cout << d - e;
	int Goc;
	double Lai;
	cout << '\n' << "Nhap tien goc: ";
	cin >> Goc;
	cout << "Nhap % lai suat / nam: ";
	cin >> Lai;
	cout << "Tong goc va lai thu duoc: " << fixed << setprecision(0) << d.LaiKep(d, e, Goc, Lai);

	return 0;
}