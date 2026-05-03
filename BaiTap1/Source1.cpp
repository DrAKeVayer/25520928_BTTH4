#include "Header1.h"

SoPhuc::SoPhuc(double _t, double _a) : thuc(_t), ao(_a) {}

SoPhuc SoPhuc::operator+(const SoPhuc& b) {
    return SoPhuc(thuc + b.getThuc(), ao + b.getAo());
}

SoPhuc SoPhuc::operator-(const SoPhuc& b) {
    return SoPhuc(thuc - b.getThuc(), ao - b.getAo());
}
SoPhuc SoPhuc::operator*(const SoPhuc& b) {
    return SoPhuc(thuc * b.getThuc() - ao * b.getAo(), thuc * b.getAo() + ao * b.getThuc());
}
SoPhuc SoPhuc::operator/(const SoPhuc& b) {
    return SoPhuc((thuc * b.getThuc() + ao * b.getAo()) / (pow(b.getThuc(), 2) + pow(b.getAo(), 2)),
        (ao * b.getThuc() - thuc * b.getAo()) / (pow(b.getThuc(), 2) + pow(b.getAo(), 2)));
}

bool SoPhuc::operator==(const SoPhuc& b) {
    return (thuc == b.getThuc() && ao == b.getAo());
}
bool SoPhuc::operator!=(const SoPhuc& b) {
    return (thuc != b.getThuc() || ao != b.getAo());
}

double SoPhuc::getThuc() const {
    return thuc;
}

double SoPhuc::getAo() const {
    return ao;
}

SoPhuc::~SoPhuc() {}

ostream& operator<<(ostream& os, const SoPhuc& b) {
    if (b.thuc == 0 && b.ao == 0) {
        os << "0";
        return os;
    }
    if (b.thuc != 0) {
        os << setprecision(3) << b.thuc;
    }
    if (b.ao > 0) {
        os << " + " << b.ao << "i";
    }
    else if (b.ao == 0) {
        return os;
    }
    else {
        os << " - " << setprecision(3) << -b.ao << "i";
    }
    return os;
}

istream& operator>>(istream& is, SoPhuc& b) {
    is >> b.thuc >> b.ao;
    return is;
}