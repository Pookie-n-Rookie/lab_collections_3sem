#include <iostream>
#include <algorithm>

using namespace std;

class IntArray {
    int size;
    int* arr;

public:
    
    IntArray(int size) : size(size), arr(new int[size]) {}

 
    IntArray(const IntArray& other) : size(other.size), arr(new int[other.size]) {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    
    
    
    void input() {
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    
    void add(const IntArray& b) {
        if (size != b.size) {
            cout << "Arrays must have the same size for addition";
            return;
        }
        IntArray result(size);
        cout << "Summation values of two arrays: ";
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + b.arr[i];
            cout << result.arr[i] << " ";
        }
        cout << endl;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    
    void Sort() {
        bool swapped = true;
        for (int i = 0; swapped; i++) {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~IntArray() {
        delete[] arr;
    }

};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    IntArray array1(n);
    array1.input();

    cout << "Array 1:" << endl;
    array1.print();

    IntArray array2(array1);
    cout << "Array 2 (copied from Array 1):" << endl;
    array2.print();

    
    array2.reverse();
    cout << "Reversed Array 2 :" << endl;
    array2.print();

   
    array2.Sort();
    cout << "Array 2 (sorted using bubble sort):" << endl;
    array2.print();

    cout << "Array 1 (unchanged):" << endl;
    array1.print();


    array1.add(array2);

    return 0;
}
