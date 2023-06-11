#include <bits/stdc++.h>
using namespace std;

class Weapon{
    protected:
        float atk;
        int nTurn;
    public:
        virtual void input() = 0;
        virtual float Attack() = 0;
        virtual void setHp(float APhuMaxHp, float APhuHp){}
        virtual float getHp(){return 0;};
        virtual bool canUse() = 0;
        int getTurn(){
            return nTurn;
        }
};

class Knife : public Weapon{
    protected:
        float length;
    public:
        virtual void input(){
            cin >> atk >> nTurn >> length;
        }
        virtual float Attack(){
            nTurn--;
            return atk*length;
        }
        virtual bool canUse(){
            return nTurn > 0;
        }
};

class Bow : public Weapon{
    protected:
        float arrow;
    public:
        virtual void input(){
            cin >> atk >> nTurn >> arrow;
        }
        virtual float Attack(){
            nTurn-=2;
            return atk*arrow/2;
        }
        virtual bool canUse(){
            return nTurn > 1;
        }
};

class Punch : public Weapon{
    public:
        float curHp;
        float maxHp;
        Punch(){
            nTurn = 1e5;
            atk = 0;
            curHp = 1e5;
        }
        virtual void input(){
        }
        virtual void setHp(float maxHp, float curHp){
            this->curHp = curHp;
            this->maxHp = maxHp;
        }
        virtual float getHp(){
            return curHp;
        }
        virtual float Attack(){
            float tmp = maxHp * 0.1;
            curHp -= tmp;
            return tmp;
        }
        virtual bool canUse(){
            return 1;
        }
};

class Character{
    protected:
        float hp, atk;
    public:
        virtual void input() = 0;
        virtual float getAtk() = 0;
        virtual bool isAlive() = 0;
        float getHp(){
            return hp;
        }
        virtual void damaged(float attack){
            hp -= attack;
        }
};

class Bull : public Character{
    public:
        int nTurn;
        virtual void input(){
            cin >> hp >> atk >> nTurn;
        }
        virtual float getAtk(){
            return atk;
        }
        virtual void damaged(float attack){
            hp -= attack;
            nTurn--;
        }
        virtual bool isAlive(){
            return hp > 0 && nTurn > 0;
        }
};

class Tiger : public Character{
    public:
        virtual void input(){
            cin >> hp >> atk;
        }
        virtual float getAtk(){
            return atk*1.5;
        }
        virtual bool isAlive(){
            return hp > 0;
        }
};

class Human : public Character{
    public:
        float maxHp;
        virtual void input(){
            cin >> hp;
            maxHp = hp;
            atk = 0;
        }
        virtual float getAtk(){
            return atk;
        }
        virtual bool isAlive(){
            return hp > 0;
        }
        void setHp(float curHp){
            hp = curHp;
        }
        
};

Weapon* weaponInput(){
    int type;
    Weapon* curWeapon = NULL;
    cin >> type;
    if (type == 1)
        curWeapon = new Knife;
    if (type == 2)
        curWeapon = new Bow;
    curWeapon->input();
    return curWeapon;
}
Character* charInput(){
    int type;
    Character* curCh = NULL;
    cin >> type;
    if (type == 1)
        curCh = new Bull;
    if (type == 2)
        curCh = new Tiger;
    curCh->input();
    return curCh;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // if (fopen("input.txt", "r")){
    //     freopen("input.txt","r",stdin);
    // }
    Human APhu;
    APhu.input();
    
    int n;
    cin >> n;
    vector<Weapon*> weapons(n);
    for (int i = 0; i<n; i++){
        weapons[i] = weaponInput();
    }
    weapons.push_back(new Punch);
    
    int m;
    cin >> m;
    vector<Character*> chars(m);
    for (int i = 0; i<m; i++){
        chars[i] = charInput();
    }

    int posCh=0, posW=0;
    while (APhu.isAlive() && posCh < m){
        if (posW < n){
            chars[posCh]->damaged(weapons[posW]->Attack());
            if (!weapons[posW]->canUse()){
                posW++;
            }
        }
        else {
            weapons[posW]->setHp(APhu.maxHp, APhu.getHp());
            chars[posCh]->damaged(weapons[posW]->Attack());
            APhu.setHp(weapons[posW]->getHp());
        }
        
        if (!chars[posCh]->isAlive())
            posCh++;
        else {
            APhu.damaged(chars[posCh]->getAtk());
        }
        // cout << APhu.getHp() << " " << posW << " " << posCh << "\n";
    }

    if (APhu.isAlive()){
        cout << "A Phu chien thang, hp con lai: " << APhu.getHp() << ", so vu khi con lai: " << n-posW;
    }
    else {
        cout << "A Phu that bai, so thu du con lai: " << m-posCh;
    }
    return 0;
}