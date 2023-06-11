#include <bits/stdc++.h>
using namespace std;
class Lop
{ 
    public:
    string lop;
    static float LenLop, CupLop;
    static vector<pair<string, pair<float, float> > > DSL;
    virtual void Nhap(){cin>>lop;}
    void DiemDanh(bool x, string lopi) 
    {
    bool found = false;
        for (auto &pair : DSL) {
            if (pair.first == lopi) {
                if (x) {
                    pair.second.first += 1;
                    LenLop += 1;
                }
                else {
                    pair.second.second += 1;
                    CupLop += 1;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            if (x) {
                DSL.push_back(make_pair(lopi, make_pair(1, 0)));
                LenLop += 1;
            }
            else {
                DSL.push_back(make_pair(lopi, make_pair(0, 1)));
                CupLop += 1;
            }
        }
    }
   // void Xuat() {cout<<"Lop: "<<lop<<", so hoc sinh len lop: "<<LenLop<<", so hoc sinh dup: "<<CupLop<<endl;}
    void Xuat() {
        for (auto& pair : DSL) {
                cout << "Lop: " << pair.first << ", so hoc sinh len lop: " << pair.second.first 
                     << ", so hoc sinh dup: " << pair.second.second << endl;
                                }
    }
};
float Lop::LenLop, Lop::CupLop = 0; 
vector<pair<string, pair<float , float> > > Lop::DSL;
class GV
{
    public:
    string name;
    float year,salary;
        virtual void Nhap(){cin>>name>>year;}
        virtual void TienLuong(){salary= year*2000000; }
    static float Tientraluong;
        virtual void TraLuong(){Tientraluong+=salary;}
};
float GV::Tientraluong = 0;
class GVCN: public GV{
    public:
    Lop *lop;
        GVCN(){lop =new Lop;}
        virtual void Nhap()  { GV::Nhap(); lop->Nhap();}
        virtual void TienLuong() {GV::TienLuong(); salary+=1000000;}
};

class GVBM: public GV
{
    public:
    string mon;
        virtual void Nhap() {GV::Nhap(); cin>>mon;}
        virtual void TienLuong()  {GV::TienLuong();}
};

class HS
{
    public:
    string name;
    float toan,ly,hoa;
    Lop *lop;
    float tienhoc;
        virtual void Nhap() {cin>>name; lop= new Lop; lop->Nhap(); cin>>toan>>ly>>hoa;}
        virtual void TienHocLai () {tienhoc=0;}
    static float hocphi;
        virtual void TinhHocPhi () {hocphi+=tienhoc;}
        virtual void DiemDanh () { float dtb = (toan+ly+hoa)/3; if (dtb>5) lop->DiemDanh(true,lop->lop); else lop->DiemDanh(false,lop->lop);}
};

bool Rot(float diem) {if (diem<5) return true; else return false;}

float HS::hocphi = 0;

class HSBT : public HS
{
    public: 
    virtual void TienHocLai () override {
        if (Rot(toan)) tienhoc+=1000000;
        if (Rot(ly)) tienhoc+=1000000;
        if (Rot(hoa)) tienhoc+=1000000;
    }

};

class HSNVK: public HS{
    public:
    virtual void TinhHocPhi () override {hocphi+=0;}
};

 GV* NhapGV()
 {
    int type;
    cin>>type;
    GV* newGV;
    if (type==1) newGV = new GVCN;
    if (type==2) newGV = new GVBM;
    newGV->Nhap();
    return newGV;
 }

 HS* NhapHS()
 {
    int type;
    cin>>type;
    HS* newHS;
    if (type==1) newHS = new HSBT;
    if (type==2) newHS = new HSNVK;
    newHS->Nhap();
    return newHS;
 }
int main()
{
    int n,m;
    cin>>n;
    vector<GV*> giaovien;
    vector<HS*> hocsinh;
    for (int i=0; i<n; i++) giaovien.push_back(NhapGV());
    cin>>m;
    for (int i=0; i<m; i++) hocsinh.push_back(NhapHS());
// CALC
    for (int i=0; i<n; i++)
{
    giaovien[i]->TienLuong();
    giaovien[i]->TraLuong();
}

    for (int i=0; i<m; i++)
{
    hocsinh[i]->TienHocLai();
    hocsinh[i]->TinhHocPhi();
    hocsinh[i]->DiemDanh();
} 


    Lop* danhsachlop = new Lop();
    danhsachlop->Xuat();
    if (GV::Tientraluong > HS::hocphi) cout <<"Khong du chi tra luong" << endl; 
    else cout<<"Du "<<fixed<<setprecision(0)<<(HS::hocphi-GV::Tientraluong)<<"d"<<endl;
//    cout<<fixed<<setprecision(0)<<(GV::Tientraluong)<<endl;
}