#include <iostream>
#include <vector>

using namespace std;

class Vector {
    int size;
    int* arr;
public:
    Vector(int size = 0) : size(size), arr(new int[size]) {}

    void input() {
        cout << "Enter the elements of the vector: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void add( Vector& b) {
        cout << "Summation Values of two vectors is: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] + b.arr[i] << " ";
        }
        cout << "\n";
    }

    void subtract(Vector& b) {
        cout << "Subtracted Values of two vectors are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] - b.arr[i] << " ";
        }
        cout << "\n";
    }

    int compare( Vector& b) {
        for (int i = 0; i < size; i++) {
            if (arr[i] < b.arr[i]) {
                return -1; 
            } else if (arr[i] > b.arr[i]) {
                return 1;
            }
        }
        return 0; 
    }

    ~Vector() {
        delete[] arr;
    }


};

int main() {
    int n;
    cout << "Enter the size of the arrays: ";
    cin >> n;

    Vector A(n), B(n);

    A.input();
    B.input();

    A.add(B);
    B.subtract(A);

    int comparisonResult = A.compare(B);
    if (comparisonResult == -1) {
        cout << "Second vector is greater than first vector\n";
    } else if (comparisonResult == 1) {
        cout << "First vector is greater than second vector\n";
    } else {
        cout << "Both the vectors are equal\n";
    }

    return 0;}
