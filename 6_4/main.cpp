#include <iostream>
#include "figure.h"
#include "triangle.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    Rectangle test(3);
    Circle test1(1);
    Rectangle test2(1, 2);
    Triangle test3(3, 4, 5);
    Figure* mas[4]{ &test, &test1, &test2, &test3 };
    for (auto i : mas) {
        i->show();
    }
}
