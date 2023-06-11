#include <iostream>
#include <cmath>

using namespace std;

class Dathuc {
    private:
        int n;
        double a[100];
    public:
        // Constructor
        Dathuc() {
            n = 0;
            for (int i = 0; i < 100; i++) {
                a[i] = 0;
            }
        }

        // Setters
        void setN(int num) {
            n = num;
        }

        void setA(int index, double value) {
            a[index] = value;
        }

        // Getters
        int getN() {
            return n;
        }

        double getA(int index) {
            return a[index];
        }

        // Input method
        void input() {
            cout << "Nhap bac cua da thuc: ";
            cin >> n;

            cout << "Nhap cac he so cua da thuc: ";
            for (int i = n; i >= 0; i--) {
                cin >> a[i];
            }
        }

        // Output method
        void output() {
            cout << "Da thuc P(x) = ";
            for (int i = n; i >= 0; i--) {
                if (a[i] != 0) {
                    if (i != n) {
                        cout << " + ";
                    }
                    if (i == 0) {
                        cout << a[i];
                    } else if (i == 1) {
                        cout << a[i] << "x";
                    } else {
                        cout << a[i] << "x^" << i;
                    }
                }
            }
            cout << endl;
        }

        // Overloaded operators
        Dathuc operator+(Dathuc B) {
            Dathuc C;
            int maxn = max(n, B.n);
            C.setN(maxn);

            for (int i = 0; i <= maxn; i++) {
                C.setA(i, a[i] + B.getA(i));
            }

            return C;
        }

        Dathuc operator-(Dathuc B) {
            Dathuc C;
            int maxn = max(n, B.n);
            C.setN(maxn);

            for (int i = 0; i <= maxn; i++) {
                C.setA(i, a[i] - B.getA(i));
            }

            return C;
        }
        double evaluate(double x) {
            double result = 0;

            for (int i = n; i >= 0; i--) {
                result += a[i] * pow(x, i);
            }

            return result;
        }
};

int main() {
    Dathuc A, B, C;

    cout << "Nhap da thuc A: " << endl;
    A.input();

    cout << "Nhap da thuc B: " << endl;
    B.input();

    C = A + B;
    cout << "Tong hai da thuc la: " << endl;
    C.output();
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    cout << "Gia tri cua P(" << x << " khi cong 2 da thuc la: " << C.evaluate(x) << endl;

    C = A - B;
    cout << "Hieu hai da thuc la: " << endl;
    C.output();

    cout << "Nhap gia tri x: ";
    cin >> x;

    cout << "Gia tri cua P(" << x << ") khi tru 2 da thuc la: " << C.evaluate(x) << endl;


    return 0;
}