#include <iostream>
#include "Header1.h"

using namespace std;

int main() { 
    SoPhuc a, b;

    cout << "Nhap 2 so phuc: " << '\n';
    cin >> a;
    cin >> b;

    cout << '\n' << "So phuc a: ";
    cout << a;
    cout << '\n' << "So phuc b: ";
    cout << b;

    cout << '\n' << "a cong b: ";
    cout << a + b;
    cout << '\n' << "a tru b: ";
    cout << a - b;

    cout << '\n' << "a nhan b: ";
    cout << a * b;

    if (b.getAo() == 0 && b.getThuc() == 0) {
        cout << '\n' << "Khong the chia cho 0";
    }
    else {
        cout << '\n' << "a chia b: ";
        cout << a / b;
    }

    cout << '\n' << "a co bang b khong?";
    if (a == b) cout << " Yes!";
    else if (a != b) cout << " Nope!";

    return 0;
}