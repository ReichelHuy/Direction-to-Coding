#include <bits/stdc++.h>
using namespace std;

class ThapPhao{
    public:
        float size, num_ammos, max_ammos;
        void nhap(){
            cin >> num_ammos;
            max_ammos = num_ammos;
        }
        void banDan(int dan){
            num_ammos -= dan;
        }
        virtual float damage(float num_crews) = 0;
};

class ML20S : public ThapPhao{
    public:
        ML20S(){ size = 152;}
        virtual float damage(float num_crews){
            return num_crews/4 * size * num_ammos;
        }
};

class F34 : public ThapPhao{
    public:
        F34(){ size = 76.2;}
        virtual float damage(float num_crews){
            return 3 * size * num_ammos;
        }
};

class D25T : public ThapPhao{
    public:
        D25T(){ size = 122;}
        virtual float damage(float num_crews){
            return 3 * size * num_ammos;
        }
};

class M65L : public ThapPhao{
    public:
        M65L(){ size = 130;}
        virtual float damage(float num_crews){
            return num_crews/4 * size * num_ammos;
        }
};

class DongCo{
    public:
        float hp, xang, maxXang;
        void nhap(){
            cin >> xang;
            maxXang = xang;
        }
        virtual void chay(float km, float weight) = 0;
};

class V2 : public DongCo{
    public:
        V2(){hp = 500;}
        virtual void chay(float km, float weight){
            xang -= 450/weight * km/100;
        }
};

class V2K : public DongCo{
    public:
        V2K(){hp = 600;}
        virtual void chay(float km, float weight){
            xang -= 450/weight * km/100;
        }
};

class _2DG8M : public DongCo{
    public:
        _2DG8M(){hp = 1000;}
        virtual void chay(float km, float weight){
            xang -= 400/weight * km/100;
        }
};

class XeTang{
    public:
        float weight, num_crews;
        string ten;
        ThapPhao *thapPhao;
        DongCo *dongCo;
        void nhap(){
            cin >> weight >> num_crews;
            thapPhao->nhap();
            dongCo->nhap();
        }
        void banDan(int dan){
            thapPhao->banDan(dan);
        }
        void chay(float km){
            dongCo->chay(km,weight);
        }
        void xuat(){
            cout << ten << ", weight: " << weight << ", number of crews: " << num_crews << ", damage: " << thapPhao->damage(num_crews) << ", performance: " << tinhHieuSuat() << "%\n";
        }
        virtual float tinhHieuSuat() = 0;
};

class SU152 : public XeTang{
    public:
        SU152(){
            ten = "SU152";
            thapPhao = new ML20S;
            dongCo = new V2K;
        }
        virtual float tinhHieuSuat(){
            return thapPhao->num_ammos/ thapPhao->max_ammos * 100;
        }
};

class KV2 : public XeTang{
    public:
        KV2(){
            ten = "KV2";
            thapPhao = new F34;
            dongCo = new V2;
        }
        virtual float tinhHieuSuat(){
            return thapPhao->num_ammos/ thapPhao->max_ammos * 100;
        }
};

class IS : public XeTang{
    public:
        IS(){
            ten = "IS";
            thapPhao = new D25T;
            dongCo = new V2K;
        }
        virtual float tinhHieuSuat(){
            return dongCo->xang/dongCo->maxXang * 100;
        }
};

class Object279 : public XeTang{
    public:
        Object279(){
            ten = "Object279";
            thapPhao = new M65L;
            dongCo = new _2DG8M;
        }
        virtual float tinhHieuSuat(){
            return num_crews/4 * 100;
        }
};

XeTang* nhapXeTang(){
    int type;
    XeTang *newXeTang;
    cin >> type;
    if (type == 1) newXeTang = new SU152;
    if (type == 2) newXeTang = new KV2;
    if (type == 3) newXeTang = new IS;
    if (type == 4) newXeTang = new Object279;
    newXeTang->nhap();
    return newXeTang;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    vector<XeTang*> tanks;
    int dan, km;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        tanks.push_back(nhapXeTang());
    }
    cin >> km >> dan;

    for (int i = 0; i<n; i++){
        tanks[i]->banDan(dan);
        tanks[i]->chay(km);
        tanks[i]->xuat();
    }
    return 0;
}