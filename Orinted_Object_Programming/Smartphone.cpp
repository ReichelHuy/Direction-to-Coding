#include <bits/stdc++.h>
using namespace std;

vector<string> DongSmartphone = {"","Venus", "Mars", "Jupiter"};
vector<string> LoaiCPU = {"","Alpha", "Beta", "Gamma"};
vector<string> DoPhanGiai = {"", "HD", "FullHD"};
vector<string> Mau = {"", "Do", "Den", "Xanh"};
vector<string> LoaiVo = {"", "Nhom", "Nhua"};

class CPU{
    public:
        string maCPU, loaiCPU, hangCPU;
        float soCore, xungNhip, giaCPU;
        void fill(){
            if (loaiCPU == "Alpha"){
                giaCPU = 200;
                soCore = 2;
                xungNhip = 1.8;
                hangCPU = "Black";
            }
            if (loaiCPU == "Beta"){
                giaCPU = 400;
                soCore = 4;
                xungNhip = 2.46;
                hangCPU = "Black";
            }
            if (loaiCPU == "Gamma"){
                giaCPU = 600;
                soCore = 4;
                xungNhip = 2.6;
                hangCPU = "White";
            }
        }
        void xuat(){
            //CPU: CPUAzen Alpha Black 2 1.8 200
            cout << "CPU: " << maCPU << " " << loaiCPU << " " << hangCPU << " " << soCore << " " << xungNhip << " " << giaCPU << "\n";
        }
};

class ManHinh{
    public:
        string maManHinh, hangSX, doPhanGiai, chongLoa = "";
        int giaManHinh;
        void fill(){
            if (doPhanGiai == "HD"){
                giaManHinh = 200;
            }
            else {
                if (chongLoa == ""){
                    giaManHinh = 300;
                } 
                else giaManHinh = 500;
            }
        }
        void xuat(){
            //Man hinh: IntelG Intel HD 200
            cout << "Man hinh: " << maManHinh << " " << hangSX << " " << doPhanGiai << " " << chongLoa << giaManHinh << "\n";
        }
};

class Vo{
    public:
        string maVo, loaiVo, hangVo, mau;
        int giaVo;
        void fill(){
            if (loaiVo == "Nhom"){
                giaVo = 400;
                hangVo = "Black";
            }
            else {
                giaVo = 200;
                hangVo = "White";
            }
        }
        void xuat(){
            //Vo smartphone: Titan Nhom Black Do 400
            cout << "Vo smartphone: " << maVo << " " << loaiVo << " " << hangVo << " " << mau << " " << giaVo << "\n";
        }
};

class Smartphone{
    public:
        string maDT, dongDT;
        int giaDT;
        CPU cpu;
        ManHinh mh;
        Vo vo;

        void Nhap(){
            int tmp;
            cin >> tmp;// dong dien thoai
            if (tmp == 3) mh.chongLoa = "Chong loa ";
            dongDT = DongSmartphone[tmp];
            cin >> maDT;// ma dien thoai
            cin >> tmp;// loai CPU
            cpu.loaiCPU = LoaiCPU[tmp];
            cin >> cpu.maCPU;// ma CPU
            cin >> mh.maManHinh >> mh.hangSX; // ma man hinh, hang san xuat
            cin >> tmp; // do phan giai
            mh.doPhanGiai = DoPhanGiai[tmp];
            cin >> tmp; // loai vo
            vo.loaiVo = LoaiVo[tmp];
            cin >> vo.maVo;// ma vo
            cin >> tmp;// mau vo
            vo.mau = Mau[tmp];
            cpu.fill();
            mh.fill();
            vo.fill();
        }

        void xuat(){
            giaDT = cpu.giaCPU + vo.giaVo + mh.giaManHinh;
            if (dongDT == "Venus")
                giaDT *= 1.3;
            else if (dongDT == "Mars")
                giaDT *= 1.5;
            else
                giaDT *= 1.8;
            
            cout << "Smartphone: " << maDT << " " << dongDT << " " << giaDT << "\n";
            cpu.xuat();
            mh.xuat();
            vo.xuat();
        }


};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n;
    cin >> n;
    vector<Smartphone> phone(n);
    for (int i = 0; i<n; i++){
        phone[i].Nhap();
    }
    for (int i = 0; i<n; i++){
        phone[i].xuat();
    }
    return 0;
}