#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int a[], int n);
void selectionsort(int a[], int n);
void insertionsort(int a[], int n);
void mergesort_1(int arr[], int lb, int ub);
void quicksort_1(int arr[], int lb, int ub);
void mergesort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid, int ub);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

int main() {
    int terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);

    int* arr1 = (int*)malloc(terms * sizeof(int));
    int* arr2 = (int*)malloc(terms * sizeof(int));
    int* arr3 = (int*)malloc(terms * sizeof(int));
    int* arr4 = (int*)malloc(terms * sizeof(int));
    int* arr5 = (int*)malloc(terms * sizeof(int));

    srand(time(0));
    for (int i = 0; i < terms; i++) {
        int t = rand() % 10000;
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = t;
    }

    quicksort_1(arr5, 0, terms - 1);
    mergesort_1(arr4, 0, terms - 1);
    insertionsort(arr3, terms);
    selectionsort(arr2, terms);
    bubblesort(arr1, terms);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);

    return 0;
}

void bubblesort(int a[], int n) {
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    printf("Bubble sort time = %lf ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
}

void selectionsort(int a[], int n) {
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
    clock_t end = clock();
    printf("Selection sort time = %lf ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
}

void insertionsort(int a[], int n) {
    clock_t start = clock();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    clock_t end = clock();
    printf("Insertion sort time = %lf ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
}

void merge(int arr[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

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

    free(L);
    free(R);
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
    clock_t start = clock();
    mergesort(arr, lb, ub);
    clock_t end = clock();
    printf("Merge sort time = %lf ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
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
    clock_t start = clock();
    quicksort(arr, low, high);
    clock_t end = clock();
    printf("Quick sort time = %lf ms\n", ((double)(end - start)) * 1000 / CLOCKS_PER_SEC);
}
