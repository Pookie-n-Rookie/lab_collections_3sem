#include <iostream>

using namespace std;

class INT {
    int i;

public:
    INT(int a) : i(a) {}

    INT(const INT& other) : i(other.i) {}

    INT& operator=(const INT& other) {
        i = other.i;
        return *this;
    }

    INT operator++() {
        ++i;
        return *this;
    }

    INT operator++(int) {
        INT temp = *this;
        ++i;
        return temp;
    }

    operator int() const {
        return i;
    }

    friend ostream& operator<<(ostream& os, const INT& obj) {
        os << obj.i;
        return os;
    }
};

int main() {
    int x = 3;
    INT y = x;
    y++ = ++y;
    x = y;
    cout << "x: " << x << ", y: " << y << endl;  
    return 0;}
