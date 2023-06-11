#include <iostream>
using namespace std;

// Hoán đổi 2 số
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// QuickSort sử dụng đệ quy
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    cout << "Dãy sau khi sắp xếp: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}