#include <time.h>

#include <algorithm>
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 99999;
    int choice;
    int *arr = new int[n];
    int *temp = new int[n];

    srand(time(NULL));
    clock_t start, end;

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 99999;
    }

    while (1) {
        cout << " Menu:\n1. Bubble Sort\n2. Insertion Sort\n3. Exit\nEnter "
                "your choice: ";
        cin >> choice;

        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }

        if (choice == 1) {
            start = clock();
            bubbleSort(temp, n);
            end = clock();
            cout << "Time taken by Bubble Sort: "
                 << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
        } else if (choice == 2) {
            start = clock();
            insertionSort(temp, n);
            end = clock();
            cout << "Time taken by Insertion Sort: "
                 << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    delete[] arr;
    delete[] temp;

    return 0;
}