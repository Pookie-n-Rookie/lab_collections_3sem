#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() { return real; }
    double getImag() { return imag; }

    void display(){
        cout << "(" << real << ", " << imag << ")";
    }
    
    bool operator==(const Complex& other)  {
        return (real == other.real && imag == other.imag);
    }
};

template <typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int size;

public:
    Stack(int s = 100) {
        arr = new T[s];
        topIndex = -1;
        size = s;
    }

    
    class Overflow {
    public:
        Overflow(const char* str) {
            cout << "Stack Overflow Exception: " << str << endl;
        }
    };

    
    class Underflow {
    public:
        Underflow(const char* str) {
            cout << "Stack Underflow Exception: " << str << endl;
        }
    };

    void push(T value) {
        if (topIndex == size - 1) {
            throw Overflow("Stack is full");
        } else {
            arr[++topIndex] = value;
        }
    }

    T pop() {
        if (topIndex == -1) {
            throw Underflow("No elements to pop");
        } else {
            return arr[topIndex--];
        }
    }

    bool empty() {
        return topIndex == -1;
    }

    T top() {
        if (topIndex == -1) {
            throw Underflow("No elements");
        }
        return arr[topIndex];
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    try {
       
        Stack<int> intStack(5);
        intStack.push(6);
        intStack.push(78);
        intStack.push(62);
        intStack.push(9);
        
        cout << "Top of int stack: " << intStack.top() << endl;

        intStack.pop();
        intStack.pop();
        cout << "Top after popping two elements: " << intStack.top() << endl;

       
        Stack<Complex> complexStack(3);
        complexStack.push(Complex(3, 4));
        complexStack.push(Complex(5, 12));
        complexStack.push(Complex(1, 1));

        cout << "Top of complex stack: ";
        complexStack.top().display();
        cout << endl;

        complexStack.pop();
        complexStack.pop();
      


        cout << "Top of complex stack after popping two elements: ";
        complexStack.top().display();
        cout << endl;
        complexStack.push(Complex(2, 2));
        complexStack.pop();
        complexStack.pop();
        complexStack.pop();  

    }
    catch (Stack<int>::Overflow ob1) {
        cout << "Overflow exception handled for int stack!" << endl;
    }
    catch (Stack<int>::Underflow ob2) {
        cout << "Underflow exception handled for int stack!" << endl;
    }
    catch (Stack<Complex>::Overflow ob1) {
        cout << "Overflow exception handled for complex stack!" << endl;
    }
    catch (Stack<Complex>::Underflow ob2) {
        cout << "Underflow exception handled for complex stack!" << endl;
    }
    catch (...) {
        cout << "Default exception caught!" << endl;
    }

    return 0;
}
