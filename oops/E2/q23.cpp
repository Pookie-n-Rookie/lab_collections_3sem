#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float img;

public:
   
    Complex(): real(0), img(0) {}

    void setReal(float r) {
        real = r;
    }

    void setImg(float i) {
        img = i;
    }

    
    float getReal()  {
        return real;
    }

    float getImg()  {
        return img;
    }

   
    void disp()  {
        if (img >= 0) {
            cout << real << " + " << img << "i" << endl;
        } else {
            cout << real << " - " << -img << "i" << endl;
        }
    }

    
    Complex sum( Complex& c) {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }
};

int main() {
      Complex c1, c2, c3;

    
    float r1, i1, r2, i2;
    
    cout << "Enter real and imaginary part for complex number 1: ";
    cin >> r1 >> i1;
    c1.setReal(r1);
    c1.setImg(i1);

    cout << "Enter real and imaginary part for complex number 2: ";
    cin >> r2 >> i2;
    c2.setReal(r2);
    c2.setImg(i2);
    
    c3 = c1.sum(c2);

    
    cout << "Complex number 1: ";
    c1.disp();

    cout << "Complex number 2: ";
    c2.disp();

    cout << "Sum of complex numbers (c1 + c2): ";
    c3.disp();

    return 0;
}
