#include <bits/stdc++.h>
using namespace std;

class ComplexRoot {
    int a, b, c;
public:
    ComplexRoot(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}

    void root() {
        double real = -b / (2.0 * a);
        double img = sqrt(abs(b * b - 4 * a * c)) / (2.0 * a);
        cout << "Complex roots are: " << real << " + i" << img << " and " << real << " - i" << img << endl;
    }
};

class Quadratic {
    int a, b, c;
public:
    Quadratic(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}

    Quadratic operator+(const Quadratic &ob) {
        return Quadratic(a + ob.a, b + ob.b, c + ob.c);
    }

    double valueAt(double x) {
        return a * x * x + b * x + c;
    }

    void root() {
        if ((b * b - 4 * a * c) < 0) {
            ComplexRoot(a, b, c).root();
        } else {
            double real = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
            double real2 = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
            cout << "Real roots are: " << real << " and " << real2 << endl;
        }
    }

    friend istream &operator>>(istream &is, Quadratic &ob) {
        cout << "Enter the coefficients of the quadratic a, b, c: ";
        is >> ob.a >> ob.b >> ob.c;
        return is;
    }

    friend ostream &operator<<(ostream &os, const Quadratic &ob) {
        os << ob.a << "x^2 + " << ob.b << "x + " << ob.c;
        return os;
    }
};

int main() {
    Quadratic q1, q2, q3;
    cin >> q1 >> q2;
    cout << q1 << endl << q2 << endl;

    q3 = q1 + q2;
    cout << "Sum of quadratics: " << q3 << endl;

    cout << "Roots of q3: ";
    q3.root();

    return 0;
}


