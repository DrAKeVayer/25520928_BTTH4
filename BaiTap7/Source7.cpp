#include "Header7.h"

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
double Vector::operator[](int i) const {
	if (i >= 0 && i < vt.size()) return vt[i];
	return -37707;
}
void Vector::push(double x) {
	vt.push_back(x);
}
int Vector::getSize() const {
	return vt.size();
}

Matrix::Matrix(int _r, int _c) : col(_c), row(_r){
	mt.reserve(_c * _r);
}
ostream& operator<<(ostream& os, const Matrix& a) {
	if (a.mt.empty()) return os;
	for (int i = 0; i < a.row; i++) {
		os << '\n';
		if (a.row == 1) {
			os << "[ ";
		}
		else if (i == 0) {
			os << "┌ ";
		}
		else if (i > 0 && i < a.row - 1) {
			os << "│ ";
		}
		if (i == a.row - 1) {
			os << "└ ";
		}
		for (int j = 0; j < a.col; j++) {
			os << a.mt[i * a.col + j] << " ";
		}
		if (a.row == 1) {
			os << " ]";
		}
		else if (i == 0) {
			os << " ┐";
		}
		else if (i > 0 && i < a.row - 1) {
			os << " │";
		}
		if (i == a.row - 1) {
			os << " ┘";
		}
	}
	return os;
}
istream& operator>>(istream& is, Matrix& a) {
	cout << "Size m row and n col: ";
	int m, n; is >> m >> n;
	a.row = m;
	a.col = n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double x; is >> x;
			a.mt.push_back(x);
		}
	}
	return is;
}
Matrix Matrix::operator+(const Matrix& b) {
	if (col != b.col || row != b.row) return Matrix(0, 0);
	Matrix res(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			res.mt.push_back(mt[i * col + j] + b.mt[i * col + j]);
		}
	}
	return res;
}
Matrix Matrix::operator-(const Matrix& b) {
	if (col != b.col || row != b.row) return Matrix(0, 0);
	Matrix res(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			res.mt.push_back(mt[i * col + j] - b.mt[i * col + j]);
		}
	}
	return res;
}
Matrix Matrix::operator*(const Matrix& b) {
	double temp;
	if (col != b.row) return Matrix(0, 0);
	Matrix res(row, b.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < b.col; j++) {
			temp = 0;
			for (int k = 0; k < col; k++) {
				temp += mt[i * col + k] * b.mt[k * b.col + j];
			}
			res.mt.push_back(temp);
		}
	}
	return res;
}
Matrix Matrix::operator*(const double& b) {
	Matrix res(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			res.mt.push_back(b * mt[i * col + j]);
		}
	}
	return res;
}
Vector Matrix::operator*(const Vector& b) {
	if (col != b.getSize()) return Vector(0);
	Vector res(row);
	for (int i = 0; i < row; i++) {
		double temp = 0;
		for (int j = 0; j < col; j++) {
			temp += mt[i * col + j] * b[j];
		}
		res.push(temp);
	}
	return res;
}
int Matrix::getCol() const {
	return col;
}