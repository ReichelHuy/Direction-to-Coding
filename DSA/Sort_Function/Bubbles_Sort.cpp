#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n);

    cout << "Dãy sau khi sắp xếp: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}