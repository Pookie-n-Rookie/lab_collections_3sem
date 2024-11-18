#include <stdio.h>
int i,j;

void printArray(int arr[], int size) {
    for ( i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        int minIdx = i;
        for ( j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;

        // Swap
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;

        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("After partitioning: ");
        printArray(arr, high + 1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for ( i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for ( j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        
        printf("After merging: ");
        printArray(arr, right + 1);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for ( i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        printf("After removing max: ");
        printArray(arr, i);
        
        heapify(arr, i, 0);
    }
}

// Main function
int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Insertion Sort:\n");
    insertionSort(arr1, n1);
    
    printf("\nSelection Sort:\n");
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr2, n1);
    
    printf("\nBubble Sort:\n");
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr3, n1);
    
    printf("\nQuick Sort:\n");
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr4, 0, n1 - 1);
    printf("Sorted Array: ");
    printArray(arr4, n1);
    
    printf("\nMerge Sort:\n");
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr5, 0, n1 - 1);
    printf("Sorted Array: ");
    printArray(arr5, n1);
    
    printf("\nHeap Sort:\n");
    int arr6[] = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr6, n1);
    printf("Sorted Array: ");
    printArray(arr6, n1);
    
    return 0;
}

