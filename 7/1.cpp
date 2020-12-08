#include <iostream>
using namespace std;
template<typename T> void swap(T& a, T& b) {
    T c(std::move(a)); a = std::move(b); b = std::move(c);
}

template <class T> const T& max(const T& a, const T& b) {
    std::cout << "Вызванна шаблонная функция max" << std::endl;    
    return (a < b) ? b : a;
}
char* maxchar(char* a, char* b) {
    std::cout << "Вызванна специализированная функция max(char*,char*) " << std::endl;
    return (a < b) ? b : a;
}
template <typename T1, typename T2>
class Complex     
{
private:
    T1 re;
    T2 im;      // действительная и мнимая части

public:
    // конструкторы 

    Complex()
    {
    };

    Complex(T1 r)
    {
        re = r;
        im = 0;
    }

    Complex(T1 r, T2 i)
    {
        re = r;
        im = i;
    }
    
    ~Complex()
    {
    }

    // оператор присваивания
    Complex& operator = (Complex& c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }


    // оператор +=
    Complex& operator += (Complex& c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // оператор сложения
    Complex operator + (const Complex& c)
    {
        return Complex(re + c.re, im + c.im);
    }

    // оператор вычитания
    Complex operator - (const Complex& c)
    {
        return Complex(re - c.re, im - c.im);
    }

    friend ostream& operator<< (ostream& out, const Complex& c)
    {
        out << "(" << c.re << ", " << c.im << ")";
        return out;
    }
    friend istream& operator>> (istream& in, Complex& c)
    {
        in >> c.re >> c.im;
        return in;
    }

};
template <class T>
class MATRIX {
private:
    T** M;
    int m;
    int n;
public:
    MATRIX()
    {
        n = m = 0;
    }


    MATRIX(int _m, int _n)
    {
        m = _m;
        n = _n;
        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];


    }



    friend std::ostream& operator<<(std::ostream& out, const MATRIX& mat) {
        for (int i = 0; i < mat.m; i++) {
            cout << endl;
            for (int j = 0; j < mat.n; j++)
                cout << mat.M[i][j] << '\t';
        }
        cout << endl;
        return cout;
    }

    friend std::istream& operator>>(std::istream& in, MATRIX& mat) {
        for (int i = 0; i < mat.m; i++)
            for (int j = 0; j < mat.n; j++)
                in >> mat.M[i][j];
        return in;
    }

    MATRIX operator+(MATRIX mat) {
        if (this->n == mat.n and this->m == mat.m) {
            MATRIX res(mat.m, mat.n);
            for (int i = 0; i < res.m; i++)
                for (int j = 0; j < res.n; j++)
                    res.M[i][j] = this->M[i][j] + mat.M[i][j];
            return res;
        }
    }
    MATRIX operator-(MATRIX mat) {
        if (this->n == mat.n and this->m == mat.m) {
            MATRIX res(mat.m, mat.n);
            for (int i = 0; i < res.m; i++)
                for (int j = 0; j < res.n; j++)
                    res.M[i][j] = this->M[i][j] - mat.M[i][j];
            return res;
        }
    }
    template <class T1, class T2>
    friend MATRIX<double> operator+(MATRIX<T1> mat1, MATRIX<T2> mat2);
    template <class T1, class T2>
    friend MATRIX<double> operator-(MATRIX<T1> mat1, MATRIX<T2> mat2);
};

template <class T1, class T2>
MATRIX<double> operator+(MATRIX<T1> mat1, MATRIX<T2> mat2) {
    if (mat1.n == mat2.n and mat1.m == mat2.m) {
        MATRIX<double> res(mat2.m, mat2.n);
        for (int i = 0; i < res.m; i++)
            for (int j = 0; j < res.n; j++)
                res.M[i][j] = mat1.M[i][j] + mat2.M[i][j];
        return res;
    }
}

template <class T1, class T2>
MATRIX<double> operator-(MATRIX<T1> mat1, MATRIX<T2> mat2) {
    if (mat1.n == mat2.n and mat1.m == mat2.m) {
        MATRIX<double> res(mat2.m, mat2.n);
        for (int i = 0; i < res.m; i++)
            for (int j = 0; j < res.n; j++)
                res.M[i][j] = mat1.M[i][j] + mat2.M[i][j];
        return res;
    }
}


int main()
{   
    setlocale(LC_ALL, "ru");
    std::cout << "Hello World!\n";
    int a = 5, b = 4;
    std::string c = "sss", d = "qqq";
    //swap(a, b);
    swap(c, d);
    std::cout << a << "\t" << b << std::endl;
    std::cout << c << "\t" << d << std::endl;
    char q[10] = "Hello";
    char z[] = "World";
    std::cout << maxchar(z, q)<< endl;

    Complex<int, int> ch(1, 4);
    Complex <float, float> ch1(1.1, 2.3);
    Complex <float, float> ch2(1.2, 2.4);
    cout << ch << endl;
    cout << ch1 << endl;
    cout << ch1+ch2 << endl;
    MATRIX<int> M1(2, 2);
    cin >> M1;
    cout << M1 << endl;
    MATRIX<double> M2(2, 2);
    cin >> M2;
    cout << M2 << endl;
    cout << M1 + M2 << endl;
    cout << M1 - M2 << endl;

    //cout << M;

}

