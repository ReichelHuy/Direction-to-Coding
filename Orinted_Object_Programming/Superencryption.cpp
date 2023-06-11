#include <bits/stdc++.h>
using namespace std;

class Decrypter{
    private:
        string s;
    public:
        Decrypter(string &st) {s = st;}
        ~Decrypter(){}
        Decrypter caesar( int key){
            string st = s;
            string ret = st;
            for (int i = 0; i<st.size(); i++){
                if ('A' <= st[i] && st[i] <= 'Z')
                    ret[i] = (st[i] -'A'- key + 26) % 26 + 'A';
                else 
                    ret[i] = (st[i] -'a'- key + 26) % 26 + 'a';
            }
            return ret;
        }
        Decrypter vigenere(int key1, int key2){
            string st = s;
            string ret = st;
            for (int i = 0; i<st.size(); i++){
                int key;
                
                if (i % 2 == 0) key = key1;
                else key = key2;

                if ('A' <= st[i] && st[i] <= 'Z')
                    ret[i] = (st[i] -'A'- key + 26) % 26 + 'A';
                else 
                    ret[i] = (st[i] -'a'- key + 26) % 26 + 'a';
            }
            return ret;
        }
        void solve(){
            for (int i = 0; i<=26; i++){
                for (int j = 0; j<=26; j++){
                    for (int k = 1; k<=25; k++){
                        string ans = (this->caesar(k)).vigenere(i,j).s;
                        if (ans.find("oop") != std::string::npos) {
                            cout << ans << '\n';
                            return;
                        }
                    }
                }
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    string s;
    cin >> s;
    Decrypter ans(s);
    ans.solve();
    
    return 0;
}