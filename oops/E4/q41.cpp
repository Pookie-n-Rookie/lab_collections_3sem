#include <iostream>
class Integer {
public:
    int value;
    Integer(int val=0) : value(val) {}
    Integer(const Integer& other) : value(other.value) {}
    Integer& operator=(const Integer& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
    Integer operator+(const Integer& other) {
        return Integer(this->value + other.value);
    }
    Integer operator++(int) {
        Integer temp = *this;
        value++;
        return temp;
    }
    friend std::ostream& operator<<(std::ostream& os, const Integer& obj) {
        os << obj.value;
        return os;
    }
};
int main() {
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a.value;
    std::cout << a << b << c;
    return 0;
}
