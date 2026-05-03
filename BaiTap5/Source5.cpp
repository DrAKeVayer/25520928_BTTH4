#include "Header5.h"
int DonThuc::getMu() const {
	return soMu;
}
double DonThuc::getHeSo() const {
	return heSo;
}
void DonThuc::setHeSo(double a) {
	heSo = a;
}
void DonThuc::setMu(int a) {
	soMu = a;
}
void DonThuc::flipSign() {
	heSo = -heSo;
}
DonThuc DonThuc::operator*(const DonThuc& other) {
	double nHeSo = heSo * other.heSo;
	int nSoMu = soMu + other.soMu;
	return DonThuc(nSoMu, nHeSo);
}

DaThuc::DaThuc(int n) {
	dt.clear();
	for (int i = 0; i <= n; i++) {
		DonThuc dont(i, 0);
		dt.push_back(dont);
	}
}
void DaThuc::Nhap(int n) {
	cout << '\n' << "Nhap lan luot bac - he so" << '\n';
	for (int i = 0; i < n; i++) {
		int o; cin >> o;
		double m; cin >> m;
		dt[i].setHeSo(m);
		dt[i].setMu(o);
	}
}
DaThuc DaThuc::operator+(const DaThuc& other) {
	DaThuc sum(-1);
	for (int i = 0; i < dt.size(); i++) {
		sum.dt.push_back(dt[i]);
	}
	for (int i = 0; i < other.dt.size(); i++) {
		sum.dt.push_back(other.dt[i]);
	}
	sum.Smush();
	return sum;
}
DaThuc DaThuc::operator-(const DaThuc& other) {
	DaThuc sum(-1);
	for (int i = 0; i < dt.size(); i++) {
		sum.dt.push_back(dt[i]);
	}
	DonThuc temp;
	for (int i = 0; i < other.dt.size(); i++) {
		temp = other.dt[i];
		temp.flipSign();
		sum.dt.push_back(temp);
	}
	sum.Smush();
	return sum;
}
DaThuc DaThuc::operator*(const DaThuc& other) {
	DaThuc mult(-1);
	mult.dt.reserve(dt.size() + other.dt.size());
	for (int i = 0; i < dt.size(); i++) {
		for (int j = 0; j < other.dt.size(); j++) {
			mult.dt.push_back(dt[i] * other.dt[j]);
		}
	}
	mult.Smush();
	return mult;
}
void DaThuc::Smush() {
	SortDsc(0, dt.size() - 1);
	int i = 0;
	while (i < dt.size()) {
		if ((i + 1 < dt.size()) && dt[i].getMu() == dt[i + 1].getMu()) {
			dt[i + 1].setHeSo(dt[i].getHeSo() + dt[i + 1].getHeSo());
			dt[i].setHeSo(0); 
		}
		i++;
	}
	for (i = dt.size() - 1; i >= 0; i--) {
		if (dt[i].getHeSo() == 0) dt.erase(dt.begin() + i);
	}
}
void DaThuc::Xuat() {
	bool printedFirst = false;
	for (int i = 0; i < dt.size() - 1; i++) {
		double h = dt[i].getHeSo();
		if (h == 0) continue;
		else if (!printedFirst && h > 0) {
			cout << h;
			printedFirst = true;
		}
		else if (h < 0) {
			cout << " - " << abs(h);
			printedFirst = true;
		}
		else if (printedFirst && h > 0) {
			cout << " + " << h;
		}
		int m = dt[i].getMu();
		if (m == 1) {
			cout << "x";
		}
		else if (m == 0) continue;
		else {
			cout << "x^" << m;
		}
	}
	cout << '\n';
}
double DaThuc::TinhGiaTri(double x) {
	double sum = 0.0;
	for (int i = 0; i < dt.size(); i++) {
		sum += dt[i].getHeSo() * pow(x, dt[i].getMu());
	}
	return sum;
}
void DaThuc::SortDsc(int low, int high) {
	if (low >= high) return;
	int pivot = dt[low + (high - low) / 2].getMu();
	int i = low;
	int j = high;

	while (i <= j) {
		while (dt[i].getMu() > pivot) i++;
		while (dt[j].getMu() < pivot) j--;
		if (i <= j) {
			swap(dt[i], dt[j]);
			i++;
			j--;
		}
	}
	if (low < j) SortDsc(low, j);
	if (i < high) SortDsc(i, high);
}