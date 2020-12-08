ï»¿#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() {
        this->i = 0;
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Base1 Ð±ÐµÐ· Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð¾Ð²" << endl;
    }

    Base1(int i):i(i) {
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Base1 Ñ Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð°Ð¼Ð¸" << endl;
    }

    void _seti(int i) {
        this->i = i;
    }
    int _geti() {
        return this->i;
    }
protected:
    int i;
};

class Base2 {
public:
    Base2() {
        strcpy_s(this->name, "ÐŸÑƒÑÑ‚Ð¾");
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Base2 Ð±ÐµÐ· Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð¾Ð²" << endl;
    }

    Base2(char* name) {
        strcpy_s(this->name, name);
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Base2 Ñ Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð°Ð¼Ð¸" << endl;
    }

    void _setname(char* name) {
        strcpy_s(this->name, name);
    }
    char* _getname() {
        return this->name;
    }
protected:
    char name[20];
};

class Derived : public Base1, public Base2 {
    friend ostream& operator <<(ostream& out, Derived& obj) {
        return out << "i: " << obj._geti() << "\nname: " << obj._getname() << "\nch: " << obj._getch() << endl;
    }
public:
    Derived() {
        strcpy_s(this->ch, "V");
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Derived Ð±ÐµÐ· Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð¾Ð²" << endl;
    }

    Derived(int i, char* name, char* ch ) : Base1(i), Base2(name) {
        strcpy_s(this->ch,ch);
        cout << "Ð—Ð°Ð¿ÑƒÑ‰ÐµÐ½ ÐºÐ¾Ð½ÑÑ‚Ñ€ÑƒÐºÑ‚Ð¾Ñ€ Derived Ñ Ð¿Ð°Ñ€Ð°Ð¼ÐµÑ‚Ñ€Ð°Ð¼Ð¸" << endl;
    }

    void _setch(char *ch) {
        strcpy_s(this->ch, ch);
    }
    char* _getch() {
        return this->ch;
    }
protected:
    char ch[2];
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Derived test;

    int i = 1;
    char name[20] = "test";
    char ch[2] = "Ð¡";
    Derived test2(i, name, ch);
    cout << test2 << endl;
}
