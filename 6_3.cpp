#include <iostream>
using namespace std;

class Figure {
public:
    virtual double area() { return 0; };
    virtual void show() {};
};

class Circle : public Figure{
public:
    Circle(double r) {
        if (r > 0) {
            this->r = r;
        }
        else {
            exit(1);
        }
    }
    double area() {
        return 3, 14 * pow(this->r, 2);
    }
    void show() {
        cout << "Круг:\t\t" << this << "\t" << sizeof(this) << "Байт" << "\nr:\t" << this->r << "\t" << &this->r << endl;

    }
protected:
    double r;
};

class Rectangle : public Figure {
public:
    Rectangle(double d1, double d2 =0) {
        this->d1 = d1;
        this->d2 = d2;
    }

    double area() {
        if ((d2 > 0) && (d2!=d1)) {
            return this->d1 * this->d2;
        }
        else {
            return pow(this->d1, 2);
        }
    }
    void show() {
        if ((d2 > 0) && (d2!=d1)) {
            cout << "Прямоугольник:\t" << this << "\t"<< sizeof(this) << "Байт"
                                    << "\nd1:\t" << this->d1 << "\t" << &this->d1
                                    << "\nd2:\t" << this->d2 << "\t" << &this->d2 << endl;
        }
        else {
            cout << "Квадрат:\t" << this << "\t" << sizeof(this) << "Байт" << "\nd:\t" << this->d1 << "\t" << &this->d1 << endl;

        }
    }
protected:
    double d1, d2;
};
int main()
{   
    setlocale(LC_ALL, "ru");
    Rectangle test(3);
    Circle test1(1);
    Rectangle test2(1, 2);
    Figure* mas[3]{ &test, &test1, &test2 };
    for(auto i : mas) {
        i->show();
    }
}

