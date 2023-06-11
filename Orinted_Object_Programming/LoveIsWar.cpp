#include <bits/stdc++.h>
using namespace std;
static int NumFriend;

class Friend{
    public:
    string Name;
    int Age;
    int Type;
    Friend (int t, string n, int a ) : Type(t), Name(n), Age(a) {};
    virtual void Out(){}
};


class BestFriend: public Friend
{
    public:
    string Phone;
    float TimeforBestFriend;
    static float total1;
    BestFriend (int T, string N, int A, string P) : Friend(T,N,A), Phone(P)  { TimeforBestFriend = 5; total1+=TimeforBestFriend;}
    virtual ~BestFriend () {}
    void  Out() override  {cout<<"Thoi gian cho ban than: "<<total1<< " h"<<endl;}
};

float BestFriend::total1 = 0; // Định nghĩa biến static

class BoyFriend : public Friend
{
    public:
    float  Income;
    float TimeforBoyFriend;
    static float total2;
    BoyFriend (int T, string N, int A, float I)  : Friend(T,N,A), Income(I) {};
    virtual ~ BoyFriend () {}
    void TimeForFriend(){ TimeforBoyFriend = 5*Income/10000000; total2+=TimeforBoyFriend;}
    void Out() override { cout <<"Thoi gian cho ban trai: "<<total2 <<" h"<<endl; }

};
float BoyFriend::total2 = 0; // Định nghĩa biến static

class OtherFriend: public Friend
{
    public:
    float Attractiveness;
    float TimeforOtherFriend;
    static float total3;
    OtherFriend (int T, string N, int A, float Atract) : Friend(T,N,A), Attractiveness(Atract) {};
    virtual ~OtherFriend() {}
    void TimeForFriend() { TimeforOtherFriend = Attractiveness*20/NumFriend; total3+= TimeforOtherFriend; }
    void Out() override { cout<<"Thoi gian cho ban trai khac: "<<total3<<" h"<<endl;}

};
float OtherFriend::total3 = 0; // Định nghĩa biến static

int main()
{
    int n;
    cin >> n;
    NumFriend = n; 
    vector <Friend*> fri ;
    vector <OtherFriend*> other ;
    vector <BoyFriend*> boy;
    vector <BestFriend*> bfriend;
BestFriend* b;
BoyFriend* c;
OtherFriend* d;

for (int i = 0; i < n; i++)
{
    int T;
    cin>>T;
    int A;
    float Time,I,Attract;
    string N,P;
    switch (T) {
        case 1:
        cin>>N>>A>>P;
        b = new BestFriend(T,N,A,P); 
        fri.push_back(b);
        bfriend.push_back(b);
        break;
        case 2:
        cin>>N>>A>>I;
        c = new BoyFriend(T,N,A,I);
        c->TimeForFriend();
        fri.push_back(c);
        boy.push_back(c);
        break;
        case 3:
        cin>>N>>A>>Attract;
        d = new OtherFriend(T,N,A,Attract); 
        fri.push_back(d);
        other.push_back(d);
        break;
    }
}

    if (other.size()!= 0) for (auto it : other) {it->TimeForFriend();}
    cout<<"Thong ke:"<<endl;
    OtherFriend* o ;
    BestFriend* bf;
    if (bfriend.size()!=0) { bf->Out();}
    if (boy.size()!=0) { b->Out();}
    if (other.size()!=0) {o->Out();}
    return 0;

}