#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        while (!s.empty() && s.top() <= height) {
            s.pop();
        }

        count += s.size();
        s.push(height);
    }

    cout << count << endl;

    return 0;
}