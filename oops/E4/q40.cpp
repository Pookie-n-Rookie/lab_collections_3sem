#include <iostream>

using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray(int s) : size(s) {
        arr = new int[size];
    }

    ~IntArray() {
        delete[] arr;
    }

    int& operator[](int index) {
        return arr[index];
    }

    friend ostream& operator<<(ostream& os, const IntArray& intArray) {
        for (int k = 0; k < intArray.size; k++) {
            os << intArray.arr[k] << " ";
        }
        return os;
    }
};

int main() {
    IntArray i(10);
    for (int k = 0; k < 10; k++)
        i[k] = k;
    cout << i;
    return 0;
}
