#include <iostream>
#include <typeinfo>
using namespace std;

class DomesticAnimal {
public:
    DomesticAnimal():weight(0), price(0), color("") {
        cout << "Вызван конструктор DomesticAnimal без параметров" << endl;
    }

    DomesticAnimal(float weight, float price, string color):weight(weight), price(price), color(color) {
        cout << "Вызван конструктор DomesticAnimal с параметрами" << endl;
    }

    void print() {
        cout << typeid(*this).name()
                << "\nweight: " << this->weight
                << "\nprice: " << this->price
                << "\ncolor: " << this->color << endl;
    }
protected:
    float weight;
    float price;
    string color;
};

class Cow : virtual public DomesticAnimal {
public:
    Cow(){
    
    }

    Cow(float weight, float price, string color): DomesticAnimal(weight, price, color) {

    }

    void print() {
        cout << typeid(*this).name()
                << "\nweight: " << this->weight
                << "\nprice: " << this->price
                << "\ncolor: " << this->color << endl;
    }
};

class Buffalo : virtual public DomesticAnimal {
public:
    Buffalo() {

    }

    Buffalo(float weight, float price, string color) : DomesticAnimal(weight, price, color) {

    }

    void print() {
        cout << typeid(*this).name()
            << "\nweight: " << this->weight
            << "\nprice: " << this->price
            << "\ncolor: " << this->color << endl;
    }
};

class Beefalo :  public Buffalo, public Cow {
    Beefalo() {
    

    }

    Beefalo(float weight, float price, string color){

    }

    void print() {
        cout << typeid(*this).name()
            << "\nweight: " << this->weight
            << "\nprice: " << this->price
            << "\ncolor: " << this->color << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    DomesticAnimal test(10, 11, "red");
    Cow test1;
    test1.print();

    test.print();
}
