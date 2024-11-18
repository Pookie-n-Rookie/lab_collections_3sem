#include<bits/stdc++.h>
using namespace std;
class Complex {
	private:
		double real;
		double imag;

	public:
		Complex(double r = 0.0, double i = 0.0) : real(r), imag(i){}
		Complex& operator=(const Complex& other) {
			if (this != &other) {
				real = other.real;
				imag = other.imag;
			}
			return *this;
		}

		Complex operator+(const Complex& other) const {
			return Complex(real + other.real, imag + other.imag);
		}

		Complex operator-(const Complex& other) const {
			return Complex(real - other.real, imag - other.imag);
		}

		Complex operator*(const Complex& other) const {
			return Complex(real * other.real - imag * other.imag,
					real * other.imag + imag * other.real);
		}

		Complex operator/(const Complex& other) const {
			double denominator = other.real * other.real + other.imag * other.imag;

			return Complex((real * other.real + imag * other.imag) / denominator,
					(imag * other.real - real * other.imag) / denominator);
		}
		friend ostream& operator<<(ostream& os, const Complex& c) {
			os << c.real;
			if (c.imag >= 0) {
				os << " + " << c.imag << "i";
			} else {
				os << " - " << -c.imag << "i";
			}
			return os;
		}
};
int main() {
	double r1,i1,r2,i2;
	cout<<"enter the real and img part of the first no. :";
	cin>>r1>>i1;
	cout<<"enter the real and img part of the first no. :";
	cin>>r2>>i2;

	Complex c1(r1, i1);
	Complex c2(r2, i2);

	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c1 + c2: " << (c1 + c2) << endl;
	cout << "c1 - c2: " << (c1 - c2) << endl;
	cout << "c1 * c2: " << (c1 * c2) << endl;
	cout << "c1 / c2: " << (c1 / c2) << endl;

	return 0;
}

