#include <bits/stdc++.h>
using namespace std;

class Friend{
    public:
        string name;
        int age;
        float time;
        Friend(){numberOfFriend++;}
        virtual void nhap(){
            cin >> name >> age;
        }
        virtual void calc() = 0;
        virtual void xuat(){
            cout << "Ten: " << name << ", tuoi: " << age;
        }
        static float bestFriendTime, boyFriendTime, otherBoyTime, numberOfFriend;
};

class BestFriend : public Friend{
    public:
        string phone;
        virtual void nhap(){
            Friend::nhap();
            cin >> phone;
        }
        virtual void calc(){
            time = 5;
            bestFriendTime += time;
        }
        virtual void xuat(){
            Friend::xuat();
            cout << ", so dien thoai: " << phone << "\n";
        }
};

class BoyFriend : public Friend{
    public:
        long long income;
        virtual void nhap(){
            Friend::nhap();
            cin >> income;
        }
        virtual void calc(){
            time = 5*income/10000000.0;
            boyFriendTime += time; 
        }
        virtual void xuat(){
            Friend::xuat();
            cout << ", thu nhap: " << income << "d\n";
        }
};

class OtherFriend : public Friend{
    public:
        float attractiveness;
        virtual void nhap(){
            Friend::nhap();
            cin >> attractiveness;
        }
        virtual void calc(){
            time = attractiveness*20/numberOfFriend;
            otherBoyTime += time;
        }
        virtual void xuat(){
            Friend::xuat();
            string doThuHut;
            if (attractiveness >= 0.7) doThuHut = "cao";
            else if (attractiveness >= 0.4) doThuHut = "trung binh";
            else doThuHut = "thap";
            cout << ", do thu hut: " << doThuHut << "*\n";
        }
};

float Friend::bestFriendTime=0, Friend::boyFriendTime=0, Friend::otherBoyTime=0, Friend::numberOfFriend=0;

Friend* nhapFriend(){
    int type;
    cin >> type;
    Friend* newFriend;
    if (type == 1) newFriend = new BestFriend;
    if (type == 2) newFriend = new BoyFriend;
    if (type == 3) newFriend = new OtherFriend;
    newFriend->nhap();
    return newFriend;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n;
    cin >> n;
    vector<Friend*> friends;
    for (float i = 0; i<n; i++){
        friends.push_back(nhapFriend());
    }

    float maxTime = 0;
    for (float i = 0; i<n; i++){
        friends[i]->calc();
        maxTime = max(maxTime, friends[i]->time);
    }
    
    cout << "Thong ke:\n";
    if (Friend::bestFriendTime > 0)
        cout << "-Thoi gian cho ban than: " << Friend::bestFriendTime << " h\n";
    if (Friend::boyFriendTime > 0)
        cout << "-Thoi gian cho ban trai: " << Friend::boyFriendTime << " h\n";
    if (Friend::otherBoyTime > 0)
        cout << "-Thoi gian cho ban trai khac: " << Friend::otherBoyTime << " h\n";
    cout << "Nguoi ban quan trong nhat:\n";
    for (int i = 0; i<n; i++){
        if (friends[i]->time == maxTime) friends[i]->xuat();
    }
    
    return 0;
}