# include <bits/stdc++.h>
using namespace std;
const int key = 13; //Khoá chặt key=13;
string decode(string s,int key)
{
   for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                s[i] = (s[i] - 'a' + 26 - key) % 26 + 'a';
            } else {
                s[i] = (s[i] - 'A' + 26 - key) % 26 + 'A';
            }
        }
    }
   return s;
}

int main()
{
    string s;
    cout << "Nhap xau s: ";
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                s[i] = (s[i] - 'a' + key) % 26 + 'a';
            } else {
                s[i] = (s[i] - 'A' + key) % 26 + 'A';
            }
        }
    }
    cout << "Xau sau khi ma hoa: " << s << endl;
    cout<<"Nhap xau can duoc giai ma: ";
    getline(cin, s);
    cout << "Xâu sau khi giải mã ROT 13| s="<<decode(s,key)<<endl;
    return 0;
}