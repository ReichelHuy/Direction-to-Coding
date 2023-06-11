#include <bits/stdc++.h>
using namespace std;

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
    cout<<"Nhap xau can duoc giai ma: ";
    getline(cin, s);
    vector <string> a; int dem=0;
    for (int key =0; key<26; key++) a.push_back(decode(s, key));
    for (auto it:a)
    {
        cout<<"Key = "<<dem<< " => Text = ";
        cout<<it<<endl;
        dem++;
    }
    return 0;
}