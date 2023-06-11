#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string convertToBase(int a, int b) {
    int mu = 0;
    int c = 1;
    while (a/c >= 1) {
        c = pow(b, mu++);
    }
    mu--;
    mu--;
    string result = "";
    while (mu >= 0) {
        int i = b - 1;
        while (i >= 0) {
            if (i * pow(b, mu) <= a) {
                result += to_string(i);
                a -= i * pow(b, mu);
                break;
            }
            i--;
        }
        mu--;
    }
    return result;
}

int main() {
    int a,b;
    cin>>a>>b;
    string result = convertToBase(a, b);
    cout << result << endl; // "146"
    return 0;
}