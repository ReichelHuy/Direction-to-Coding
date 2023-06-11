#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    char MSSV[8];
    char NAME[30];
    int Toan, Van;
public:
    void Nhap();
    void Xuat();
};

void SinhVien::Nhap() {
    cout << "Nhap MSSV: ";
    cin.getline(MSSV, 8);
    cout << "Nhap ho ten: ";
    cin.getline(NAME, 30);
    cout << "Nhap diem Toan: ";
    cin >> Toan;
    cout << "Nhap diem Van: ";
    cin >> Van;
}

void SinhVien::Xuat() {
    cout << "MSSV: " << MSSV << endl;
    cout << "Ho ten: " << NAME << endl;
    cout << "Diem Toan: " << Toan << endl;
    cout << "Diem Van: " << Van << endl;
}

int main() {
    SinhVien a;
    a.Nhap();
    a.Xuat();
    return 0;
}
