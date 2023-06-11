#include <bits/stdc++.h>
using namespace std;

int t;

struct DongVat{
    public:
        int n;
        DongVat(int x = 0) : n(x){};
};

struct Tho : public DongVat{
    private:
        vector<int> a[3];
    public:
        Tho(int x = 0){
            for (int i = 0; i<3; i++)
                a[i].resize(t+1);
            n = x;
            a[0][0] = 0; a[1][0] = 0; a[2][0] = n;
            
            for (int i = 1; i<=t; i++){
                a[2][i] = a[2][i-1] + a[1][i-1];
                a[1][i] = a[0][i-1];
                a[0][i] = a[2][i]/2;
            }
        }
        void xuat(){
            int ret = a[0][t] + a[1][t] + a[2][t];
            cout << "Tho: " << ret << ",0" << "\n"; 
        }
};

struct BoCuuDe : public DongVat{
    protected:
        vector<int> a[5];
    public:
        BoCuuDe(int x = 0){
            for (int i = 0; i<5; i++)
                a[i].resize(t+1);
            n = x;
            for (int i = 0; i<4; i++)
                a[i][0] = 0;
            a[4][0] = n;

            for (int i = 1; i<=t; i++){
                a[4][i] = a[4][i-1] + a[3][i-1];
                for (int j = 1; j<4; j++)
                    a[j][i] = a[j-1][i-1];
                a[0][i] = a[4][i]/2;
            }
        }
        
};

struct Bo : public BoCuuDe{
    public: 
        Bo(int x = 0): BoCuuDe(x){}
        void xuat(){
            int ret1 = a[0][t] + a[1][t] + a[2][t] + a[3][t] + a[4][t];
            int ret2 = 0;
            for (int i = 1; i<=t; i++) ret2 += a[4][i]*10;
            cout << "Bo: " <<  ret1 << "," << ret2 << "\n";
        }
};

struct Cuu : public BoCuuDe{
    public: 
        Cuu(int x = 0):BoCuuDe(x){}
        void xuat(){
            int ret1 = a[0][t] + a[1][t] + a[2][t] + a[3][t] + a[4][t];
            int ret2 = 0;
            for (int i = 1; i<=t; i++) ret2 += a[4][i]*5;
            cout << "Cuu: " <<  ret1 << "," << ret2 << "\n";
        }
};

struct De : public BoCuuDe{
    public: 
        De(int x = 0):BoCuuDe(x){}
        void xuat(){
            int ret1 = a[0][t] + a[1][t] + a[2][t] + a[3][t] + a[4][t];
            int ret2 = 0;
            for (int i = 1; i<=t; i++) ret2 += a[4][i]*8;
            cout << "De: " <<  ret1 << "," << ret2 << "\n";
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int bo,cuu,de,tho;
    cin >> bo >> cuu >> de >> tho >> t;
    Bo b(bo);
    Cuu c(cuu);
    De d(de);
    Tho th(tho);
    b.xuat();
    c.xuat();
    d.xuat();
    th.xuat();
    return 0;
}