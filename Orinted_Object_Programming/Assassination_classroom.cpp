#include <bits/stdc++.h>
using namespace std;

class GiaoVien{
    public:
        string ten = "";
        int soNamKinhNghiem = 0;
        virtual void nhap(){
            cin >> ten >> soNamKinhNghiem;
        }
        virtual int tinhLuong() = 0;
        static int tongLuongGV;
};

class GVCN : public GiaoVien{
    public:
        string tenLop;
        virtual void nhap(){
            GiaoVien::nhap();
            cin >> tenLop;
        }
        virtual int tinhLuong(){
            return soNamKinhNghiem * 2000000 + 1000000; 
        }
};

class GVBM : public GiaoVien{
    public:
        string tenMon;
        virtual void nhap(){
            GiaoVien::nhap();
            cin >> tenMon;
        }
        virtual int tinhLuong(){
            return soNamKinhNghiem * 2000000; 
        }
};

class HocSinh{
    public:
        string ten = "",lop = "";
        float diemToan = 0,diemLy = 0,diemHoa = 0;
        void nhap(){
            cin >> ten >> lop >> diemToan >> diemLy >> diemHoa;
        }
        bool lenLop(){
            if ((diemToan+diemLy+diemHoa)/3 > 5) return true;
            return false; 
        }
        virtual int tinhTienHocLai() = 0;
        static int tongTienHocLai;
};

class HSBT : public HocSinh{
    public:
        virtual int tinhTienHocLai(){
            int soMonHocLai = 0;
            if (diemToan < 5) soMonHocLai++;
            if (diemLy < 5) soMonHocLai++;
            if (diemHoa < 5) soMonHocLai++;
            return soMonHocLai*1000000; 
        }
};

class HSNVK : public HocSinh{
    public:
        virtual int tinhTienHocLai(){
            return 0;
        }
};

GiaoVien* nhapGV(){
    int type;
    cin >> type;
    GiaoVien* tmp;
    if (type == 1) tmp = new GVCN;
    else tmp = new GVBM;
    tmp->nhap();
    return tmp;
}

HocSinh* nhapHS(){
    int type;
    cin >> type;
    HocSinh* hs;
    if (type == 1) hs = new HSBT;
    else hs = new HSNVK;
    hs->nhap();
    return hs;
}

int GiaoVien::tongLuongGV = 0, HocSinh::tongTienHocLai = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int m;
    cin >> m;
    vector<GiaoVien*> gv(m);
    for (int i = 0; i<m; i++)
        gv[i] = nhapGV();

    int n;
    cin >> n;
    vector<HocSinh*> hs(n);
    for (int i = 0; i<n; i++)
        hs[i] = nhapHS();

    map<string,pair<int,int>> lop;
    for (int i = 0; i<n; i++){
        if (hs[i]->lenLop()) lop[hs[i]->lop].first++;
        else lop[hs[i]->lop].second++;
    }

    for (int i = 0; i<m; i++)
        GiaoVien::tongLuongGV += gv[i]->tinhLuong();
    for (int i = 0; i<n; i++)
        HocSinh::tongTienHocLai += hs[i]->tinhTienHocLai();
    map<string,bool> daXuat;
    for (int i = 0; i<n; i++){
        if (daXuat[hs[i]->lop]) continue;
        daXuat[hs[i]->lop] = 1;
        cout << "Lop: " << hs[i]->lop << ", so hoc sinh len lop: " << lop[hs[i]->lop].first << ", so hoc sinh dup: " << lop[hs[i]->lop].second << "\n";
    }
    if (GiaoVien::tongLuongGV <= HocSinh::tongTienHocLai) cout << "Du " << HocSinh::tongTienHocLai - GiaoVien::tongLuongGV  << "d";
    else cout << "Khong du chi tra luong";

    return 0;
}