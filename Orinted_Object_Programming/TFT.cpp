#include <bits/stdc++.h>
using namespace std;

int n,m;
bool Sh,Z;

class Champ{
    public:
        int damage, order, level;
        void nhap(int i){
            cin >> damage;
            order = i;
            level = 1;
        }
        friend bool operator < (Champ champ2, Champ champ1){
            return champ1.order < champ2.order;
        }
};

class Shaco : public Champ{
    public:
        void print(){
            cout << "Shaco - " << sumDamage() << "\n"; 
        }
        int sumDamage(){
            int extra = 0;
            if (Sh && Z) extra = 10;
            return (damage+extra)*m*2;
        }
};

class Zed : public Champ{
    public:
        void print(){
            cout << "Zed - " << sumDamage() << "\n"; 
        }
        int sumDamage(){
            int extra = 0;
            if (Sh && Z) extra = 10;
            return (damage+extra)*m + (damage + extra)*2*(m/3);
        }
};

template<class T>
T levelUp(T chmp1, T chmp2, T chmp3){
    T newchmp;
    newchmp.level = chmp1.level + 1;
    newchmp.order = chmp3.order;
    newchmp.damage = (chmp1.damage + chmp2.damage + chmp3.damage)*newchmp.level;
    return newchmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> m;   
    vector<Shaco> sh;
    vector<Zed> z;
    int tmp;
    for (int i = 0; i<n; i++){
        cin >> tmp;
        if (tmp == 1){
            Sh = 1;
            Shaco chmp;
            chmp.nhap(i);
            sh.push_back(chmp);
            while (sh.size() >= 3 && sh[i-2].level == sh[i].level && sh[i].level != 3){
                Shaco newchmp = levelUp<Shaco>(sh[i],sh[i-1],sh[i-2]);
                sh.pop_back(); sh.pop_back(); sh.pop_back();
                sh.push_back(newchmp);
            }
        }
        else {
            Z = 1;
            Zed chmp;
            chmp.nhap(i);
            z.push_back(chmp);
            while (z.size() >= 3 && z[i-2].level == z[i].level && z[i].level != 3){
                Zed newchmp = levelUp<Zed>(z[i],z[i-1],z[i-2]);
                z.pop_back(); z.pop_back(); z.pop_back();
                z.push_back(newchmp);
            }
        }
    }
    int i=0,j=0;
    while (i<sh.size() || j<z.size()){
        if (j>=z.size() || (i<sh.size() && sh[i].order < z[j].order)){
            sh[i].print();
            i++;
        }
        else {
            z[j].print();
            j++;
        }
    }

    return 0;
}