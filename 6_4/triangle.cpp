#include "triangle.h"
#include <iostream>

using namespace std;

//Triangle
Triangle::Triangle(double a, double b, double c) {
    if ((a + b > c || b + c > a || c + a > b) && (a != 0 && b != 0 && c != 0)) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    else {
        exit(1);
    }
        
}

double Triangle::area() {
    double p = (a + b + c) / 2;
    return  sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::show() {
    cout << "Треугольник:\t" << this << "\t" << sizeof(*this) << "Байт"
        << "\na:\t" << this->a << "\t" << &this->a
        << "\nb:\t" << this->b << "\t" << &this->b 
        << "\nc:\t" << this->c << "\t" << &this->c << endl;
}
