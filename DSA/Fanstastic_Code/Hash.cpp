#include<bits/stdc++.h>
using namespace std;

const int P = 100000007;// Số nguyên tố 
const int M = 100007; //kích thước bẳng băm

int hash_func(string key) {
    int value = 0;
    int n = key.size();
    for (int i = 0; i < n; i++) {
        value += (key[i] -'0') * (1 << i); //lấy 0 hoặc 1 chứ không phải lấy giá trị trong bảng mã asciII, ta sẽ dịch chuyển i bit sang trái
        value %= P; //tránh cho value bị tràn số
    }
    value %= P;
    return value ;
}

int main() {
    vector<string> data;
    //đẩy dữ liệu vào
    data.push_back("1010101010");
    data.push_back("0010010010");
    data.push_back("1110000111");
    data.push_back("1101100010");
    data.push_back("0101010101");

    vector<vector<string> > hash_table(M);
    for (string key : data) {
        int index = hash_func(key);
        hash_table[index].push_back(key);
    }
    for (int i = 0; i < M; i++) {
        if (hash_table[i].size() > 0) {
            cout << "Slot " << i << ": ";
            for (string key : hash_table[i]) {
                cout << key << ", ";
            }
            cout << endl;
        }
    }
    return 0;
}