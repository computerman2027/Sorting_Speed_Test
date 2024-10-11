#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SpeedTestSorting {
public:
    void main() {
        int terms;
        cout << "Enter number of terms: ";
        cin >> terms;

        int* arr1 = new int[terms];
        int* arr2 = new int[terms];
        int* arr3 = new int[terms];
        int* arr4 = new int[terms];
        int* arr5 = new int[terms];

        for (int i = 0; i < terms; i++) {
            int t = rand() % 10000;
            arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = t;
        }

        quicksort_1(arr5, 0, terms - 1);
        mergesort_1(arr4, 0, terms - 1);
        insertionsort(arr3, terms);
        selectionsort(arr2, terms);
        bubblesort(arr1, terms);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
    }

    void bubblesort(int a[], int n) {
        double start = clock();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
        double end = clock();
        cout << "Bubble sort time = " << (end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    }

    void selectionsort(int a[], int n) {
        double start = clock();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[minIndex]) {
                    minIndex = j;
                }
            }
            swap(a[i], a[minIndex]);
        }
        double end = clock();
        cout << "Selection sort time = " << (end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    }

    void insertionsort(int a[], int n) {
        double start = clock();
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
        double end = clock();
        cout << "Insertion sort time = " << (end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    }

    void merge(int arr[], int lb, int mid, int ub) {
        int n1 = mid - lb + 1;
        int n2 = ub - mid;
        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[lb + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = lb;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void mergesort(int arr[], int lb, int ub) {
        if (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            mergesort(arr, lb, mid);
            mergesort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);
        }
    }

    void mergesort_1(int arr[], int lb, int ub) {
        double start = clock();
        mergesort(arr, lb, ub);
        double end = clock();
        cout << "Merge sort time = " << (end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

    void quicksort_1(int arr[], int low, int high) {
        double start = clock();
        quicksort(arr, low, high);
        double end = clock();
        cout << "Quick sort time = " << (end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    }
};

int main() {
    SpeedTestSorting obj;
    obj.main();
    return 0;
}
