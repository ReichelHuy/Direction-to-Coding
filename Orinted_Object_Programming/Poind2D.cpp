# include <bits/stdc++.h>
using namespace std;

class Point2D 
{
     private:
     int x, y;

     public:
 void Nhap (Point2D &a){cin >> a.x >> a.y;}
 void Xuat (Point2D &a){cout<<a.x<<" "<<a.y<<endl;}
//  void SwapValuexy (int &x, int &y){ int change = x;  x=y; y= change;}
//  void ChangeValue (int &x, int &y, int Value1, int Value2) { x=Value1; y=Value2;}
//  int getx() { return x; }
//  int gety() { return y; }
//  void Convert (int &x, int &y, int AddValueX, int AddValueY) { x=x+AddValueX; y=y+AddValueY;}
};

int main()
{
    Point2D point;
    cout<<"Nhap Point 2d";
    point.Nhap(point);
    point.Xuat(point);
}