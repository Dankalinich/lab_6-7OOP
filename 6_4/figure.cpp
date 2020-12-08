#include "figure.h"
#include <iostream>

using namespace std;

//Circle
Circle::Circle(double r) {
    if (r > 0) {
        this->r = r;
    }
    else {
        exit(1);
    }
}
double Circle::area() {
    return 3, 14 * pow(this->r, 2);
}
void Circle::show() {
    cout << "Круг:\t\t" << this << "\t" << sizeof(*this) << "Байт" << "\nr:\t" << this->r << "\t" << &this->r << endl;

}
// Rectangle
Rectangle::Rectangle(double d1, double d2) {
    this->d1 = d1;
    this->d2 = d2;
}

double Rectangle::area() {
    if ((d2 > 0) && (d2 != d1)) {
        return this->d1 * this->d2;
    }
    else {
        return pow(this->d1, 2);
    }
}
void Rectangle::show() {
    if ((d2 > 0) && (d2 != d1)) {
        cout << "Прямоугольник:\t" << this << "\t" << sizeof(*this) << "Байт"
            << "\nd1:\t" << this->d1 << "\t" << &this->d1
            << "\nd2:\t" << this->d2 << "\t" << &this->d2 << endl;
    }
    else {
        cout << "Квадрат:\t" << this << "\t" << sizeof(*this) << "Байт" << "\nd:\t" << this->d1 << "\t" << &this->d1 << endl;

    }
}
