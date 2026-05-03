#include "Header3.h"

int main() {
	Time t;
	cin >> t;
	cout << '\n' << t;
	t.ShowTime();
	++t;
	cout << '\n' << t;
	--t;
	cout << '\n' << t;
	cout << '\n' << "Nhap so giay cong them: ";
	int s; cin >> s;
	t = t + s;
	cout << t;
	cout << '\n' << "Nhap so giay tru di: ";
	cin >> s;
	t = t - s;
	cout << t;
	return 0;
}