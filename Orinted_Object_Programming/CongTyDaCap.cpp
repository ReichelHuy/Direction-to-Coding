#include <bits/stdc++.h>
using namespace std;

int tongSoSanPham, tongSoNgay;


class NhanVien{
    public:
        string tennv;
        virtual void nhap() = 0;
        virtual void xuat() = 0;
};

class SanXuat : public NhanVien{
    public: 
        float luongCanBan;
        int soSanPham;
        float luong(){
            return luongCanBan + 5*soSanPham;
        }
        void nhap(){
            cin >> tennv >> luongCanBan >> soSanPham;
            tongSoSanPham += soSanPham; 
        }
        void xuat(){
            cout << tennv << ": " << luong() << "\n";
        }
};

class VanPhong : public NhanVien{
    public:
        int soNgay;
        float luong(){
            return 100*soNgay;
        }
        void nhap(){
            cin >> tennv >> soNgay; 
            tongSoNgay += soNgay;
        }
        void xuat(){
            cout << tennv << ": " << luong() << "\n";
        }
};

class Sep : public NhanVien{
    public:
        float luong(){
            return 100 + 2 * tongSoSanPham + 40 * tongSoNgay;
        }
        void nhap(){
            cin >> tennv; 
        }
        void xuat(){
            cout << tennv << ": " << luong() << "\n";
        }
};


int main()
{
    tongSoSanPham = 0;
    tongSoNgay = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n;
    cin >> n;
    vector<NhanVien*> a(n);
    for (int i = 0; i<n; i++){
        int t;
        cin >> t;
        if (t == 1){
            a[i] = new SanXuat;
            a[i]->nhap();
        }
        if (t == 2){
            a[i] = new VanPhong;
            a[i]->nhap();
        }
        if (t == 3){
            a[i] = new Sep;
            a[i]->nhap();
        }
    }
    for (int i = 0; i<n; i++){
        a[i]->xuat();
    }
    return 0;
}