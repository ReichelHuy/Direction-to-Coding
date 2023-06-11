#include <bits/stdc++.h>
using namespace std;

const float PI = 3.14;

class Chai{
    public:
        virtual void nhap() = 0;
        virtual float tinhDienTich() = 0;
        virtual float tinhTheTich() = 0;
};

class Tru : public Chai{
    private:
        float r,h;
    public:
        Tru(float R=0, float H=0): r(R),h(H){}

        virtual void nhap(){
            float R,H;
            cin >> H >> R;
            r = R, h=H;
        }

        virtual float tinhDienTich(){
            return 2*PI*r*h;
        }
        
        virtual float tinhTheTich(){
            return PI*r*r*h;
        }
};

class Hop : public Chai{
    private:
        float w,l,h;
    public: 
        Hop(float width = 0, float length = 0, float height = 0): w(width), l(length), h(height){};
        
        virtual void nhap(){
            float width, length, height;
            cin >> width >> length >> height;
            w = width, l = length, h = height;
        }

        virtual float tinhDienTich(){
            return 2*w*h + 2*l*h + 2*w*l;
        }
        
        virtual float tinhTheTich(){
            return w*l*h;
        }

};

class LapPhuong : public Chai{
    private:
        float a;
    public:
        LapPhuong(float canh = 0): a(canh) {}

        virtual void nhap(){
            float canh;
            cin >> canh;
            a = canh;
        }

        virtual float tinhDienTich(){
            return 6*a*a;
        }
        
        virtual float tinhTheTich(){
            return a*a*a;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    float n;
    cin >> n;
    vector<Chai*> a(n);

    float tongDienTich = 0, tongTheTich = 0;

    for(float i = 0; i<n; i++){
        float loai;
        cin >> loai;
        if (loai == 1){
            a[i] = new Tru;
        }
        if (loai == 2){
            a[i] = new Hop;
        }
        if (loai == 3){
            a[i] = new LapPhuong;
        }
        a[i]->nhap();
    }

    for (float i = 0; i<n; i++){
        tongDienTich += a[i]->tinhDienTich();
        tongTheTich += a[i]->tinhTheTich();
    }

    cout << "Dien tich chai vo: " << tongDienTich << "\n";
    cout << "Luong nuoc tren mat dat: " << tongTheTich/10 << "\n";
    return 0;
}