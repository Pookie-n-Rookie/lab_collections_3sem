#include <iostream>
#include <cmath>
#include <cstring>  // Include to use strcmp
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() { return real; }
    double getImag() { return imag; }

    double magnitude()const {
        return sqrt(real * real + imag * imag);
    }

    bool operator>(const Complex& other) {
        return magnitude() > other.magnitude();
    }

    void display() {
        cout << "(" << real << "+ i"<< imag << ")";
    }
};

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <>
const char* maximum<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    int x = 5, y = 8;
    cout << "Max of " << x << " and " << y << " is: " << maximum(x, y) << endl;

    Complex c1(3, 4), c2(5, 12);
    cout << "Max of complex numbers of ";
    c1.display();
     cout<<" and ";
    c2.display();
    cout<<" is";
    Complex maxComplex = maximum(c1, c2);
    maxComplex.display();
    cout << endl;

    const char* str1 = "apple";
    const char* str2 = "banana";
    cout << "Max of \"" << str1 << "\" and \"" << str2 << "\" is: " << maximum(str1, str2) << endl;

    return 0;
}
