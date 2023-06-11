#include <iostream>
#include <chrono>
#include <algorithm>
#include <numeric> 
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
#define N 10

// Hoán đổi 2 số
void swapvalues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swapvalues(arr[i], arr[j]);
        }
    }
    swapvalues(arr[i+1], arr[high]);
    return i + 1;
}

// QuickSort sử dụng đệ quy
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

// HeapSort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// MergeSort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng con
    int L[n1], R[n2];

    // Gán giá trị của arr sang L, R
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gộp 2 mảng con lại, ban đầu là ít nhất trước
    i = 0; // Chỉ mục ban đầu của mảng con đầu tiên
    j = 0; // Chỉ mục ban đầu của mảng con thứ hai
    k = l; // Chỉ mục ban đầu của mảng trộn
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm chính gọi hàm đệ quy MergeSort
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        // Tương đương với (l+r)/2, nhưng tránh tràn số khi l,r lớn
        int m = l + (r - l) / 2;

        // Gọi hàm đệ quy tới khi mảng con chỉ còn một phần tử trở lên
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        // Gộp 2 mảng con vừa chia
        merge(arr, l, m, r);
    }
}

int main() {
    int data[100000][N];

    // Tạo 8 dãy ngẫu nhiên
    for (auto& row : data) {
        generate_n(row, N, rand);
    }

    // Tạo dãy thứ nhất tăng dần
    iota(begin(data[8]), end(data[8]), 0.0);

    // Tạo dãy thứ hai giảm dần
    for (int i = 0, j = N - 1; i < N; i++, j--) {
        data[9][j] = i;
    }

    // Sắp xếp dãy thứ hai giảm dần
    sort(begin(data[9]), end(data[9]), greater<double>());

    // Đo thời gian chạy của 4 thuật toán sắp xếp
    cout << "Thoi gian chay QuickSort: ";
    auto startQuickSort = steady_clock::now();
    for (auto& row : data) {
        quicksort(row, 0, N - 1);
    }
    auto stopQuickSort = steady_clock::now();
    duration<double, milli> elapsedQuickSort = stopQuickSort - startQuickSort;
    cout << elapsedQuickSort.count() << " ms" << endl;

    cout << "Thoi gian chay HeapSort: ";
    auto startHeapSort = steady_clock::now();
    for (auto& row : data) {
        heapsort(row, N);
    }
    auto stopHeapSort = steady_clock::now();
    duration<double, milli> elapsedHeapSort = stopHeapSort - startHeapSort;
    cout << elapsedHeapSort.count() << " ms" << endl;

    cout << "Thoi gian chay MergeSort: ";
    auto startMergeSort = steady_clock::now();
    for (auto& row : data) {
        mergesort(row, 0, N - 1);
    }
    auto stopMergeSort = steady_clock::now();
    duration<double, milli> elapsedMergeSort = stopMergeSort - startMergeSort;
    cout << elapsedMergeSort.count() << " ms" << endl;

    cout << "Thoi gian chay sort (C++ STL): ";
    auto startSort = steady_clock::now();
    for (auto& row : data) {
        sort(begin(row), end(row));
    }
    auto stopSort = steady_clock::now();
    duration<double, milli> elapsedSort = stopSort - startSort;
    cout << elapsedSort.count() << " ms" << endl;

    return 0;
}