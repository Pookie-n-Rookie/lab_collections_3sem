#include <iostream>
using namespace std;

class Index {
private:
int value;
public:
Index(int v = 0) : value(v) {}
operator int() const {
return value;
}
Index operator+(const Index& other) const {
return Index(this->value + other.value);
}
Index& operator=(int v) {
value = v;
return *this;
}
Index& operator=(const Index& other) {
value = other.value;
return *this;
}
};

class Integer {
private:
int value;
public:
Integer() : value(0) {}
Integer& operator=(const Index& index) {
value = static_cast<int>(index);
return *this;
}
operator int() const {
return value;
}
};

int main() {
Index in(4), out(10);
int x = in;
int y = in + out;
in = 2;
Integer i;
i = in;

cout << "x: " << x << "\n";
cout << "y: " << y << "\n";
cout << "in: " << static_cast<int>(in) << "\n";
cout << "i: " << static_cast<int>(i) << "\n";

return 0;
}

