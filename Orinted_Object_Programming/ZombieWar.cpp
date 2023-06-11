#include <bits/stdc++.h>
using namespace std;

// declear 
class Info;
class Solider;
class Citizen;
class Zombie;
double distance(double x1, double y1, double x2, double y2) {return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}
void move_opposite( double &x1, double &y1, double x2, double y2, double speed)
{
        double dx = x1 - x2;    double dy = y1 - y2;  double maxDelta = max(abs(dx),abs(dy));
            if (maxDelta == 0) {return;}                                           // catched 
            if (0 != dx)  {double step = dx>0 ? 1:-1;x1+=step*speed;}  // move along the x-axis 
            if (0 != dy) {double step = dy>0 ? 1:-1; y1+=step*speed;}  // move along the y-axis      
}

void move_direct( double &x1, double &y1, double x2, double y2, double speed)
{
    double dx = x1 - x2;    double dy = y1 - y2;    double maxDelta = max(abs(dx),abs(dy));
            if (maxDelta == 0) {return;} // catched 
            if (0!=dx) {double step = dx>0 ? -1:1;x1+=step*speed;} // move along the x-axis 
            if (0!=dy) {double step = dy>0 ? -1:1;y1+=step*speed;} // move along the y-axis
}
// Class Build

class Info
{
    public:
        string ID;
        int  type;
        double  x,y;
    virtual void Nhap() {cin>>x>>y;}
    virtual void Xuat() {cout<<"ID: "<<ID<<", type: "<<type<<",Toa do x: "<<x << ", y: "<<y<<endl;}
};

// class HiepSi 
class Solider : public Info
{
    public:
        double level;
        static vector <Solider*> soliders;
    Solider () {type = 1;}
    virtual void Nhap() {cin>>level; Info::Nhap();}
    void KillZombie();

};
vector <Solider*> Solider:: soliders;

// class DanThuong 
class Citizen : public Info
{
    public:
        double speed;
        double intuition; 
        static vector <Citizen*> citizens;
    Citizen () {type = 2;}
    virtual void Nhap() {cin>>speed>>intuition; Info::Nhap();}
    Zombie* FindNearestZombie();
    virtual void Move(); 
};
vector <Citizen*> Citizen:: citizens;

// class zombie
class Zombie : public Info
{
    public:
        double speed;
        static vector <Zombie*> zombies;
    Zombie () {type =3;}
    virtual void Nhap() {cin>>speed; Info::Nhap();}
    Solider* FindNearestSolider();
    Citizen* FindNearestCitizen();
    virtual void Move();
    virtual void LayNhiem();
};
vector <Zombie*> Zombie:: zombies;

// I.Citizen function 
//1. Find nearest zombie
    Zombie* Citizen::FindNearestZombie(){  
        // No zombie;
        if (Zombie::zombies.empty()) return nullptr;
        // First zombie 
        Zombie* nearestZombie = Zombie::zombies[0];
        double minDistance = distance(x,y,nearestZombie->x, nearestZombie ->y);
        // The others
        for (auto zombie: Zombie::zombies) {
            double d= distance(x,y,zombie->x, zombie->y);
            if (d < minDistance) { minDistance = d; nearestZombie = zombie;}}
                return nearestZombie;
                                        }

//2. Move opposite
void Citizen::Move(){
        Zombie* nearestZombie = FindNearestZombie();
        if (nearestZombie != nullptr){
            double zombieX = nearestZombie->x;
            double zombieY = nearestZombie->y;
            move_opposite(x,y,zombieX,zombieY,speed);} else return;} // Stay if no zombie nearby

// II. Zombie function
//1. Find nearest Solider 
Solider* Zombie:: FindNearestSolider()
{
    if (Solider::soliders.empty()) return nullptr;
    Solider* nearestSolider = Solider::soliders[0];
    double minDistance = distance(x, y, nearestSolider->x, nearestSolider->y);
    for (auto solider : Solider::soliders) {
        double d = distance(x, y, solider->x, solider->y);
        if (d < minDistance) {minDistance = d;nearestSolider = solider;}
    }
    return nearestSolider;
}

//2. Find nearest Citizen
Citizen* Zombie::FindNearestCitizen()
{
    if (Citizen::citizens.empty()) return nullptr;
    Citizen* nearestCitizen = Citizen::citizens[0];
    double minDistance = distance(x, y, nearestCitizen->x, nearestCitizen->y);
    for (auto citizen : Citizen::citizens) {
        double d = distance(x, y, citizen->x, citizen->y);
        if (d < minDistance) {minDistance = d;nearestCitizen = citizen;}
    }   
    return nearestCitizen;
}

//3. Move 
void Zombie::Move()
{
    Solider* nearestSolider = FindNearestSolider();
    Citizen* nearestCitizen = FindNearestCitizen();
    if (nearestSolider == nullptr && nearestCitizen == nullptr) {return;}
    double targetX, targetY;
    // Targeting aim 
    if (nearestSolider != nullptr && nearestCitizen != nullptr) {
        // Both solider and citizen nearby, move towards the nearest one
        double soliderDistance = distance(x, y, nearestSolider->x, nearestSolider->y);
        double citizenDistance = distance(x, y, nearestCitizen->x, nearestCitizen->y);
        if (soliderDistance < citizenDistance) {
            targetX = nearestSolider->x;
            targetY = nearestSolider->y;
        } else {
            targetX = nearestCitizen->x;
            targetY = nearestCitizen->y;
        }
    } else if (nearestSolider != nullptr) {
        // Only solider nearby, move towards the solider
        targetX = nearestSolider->x;
        targetY = nearestSolider->y;
    } else {
        // Only citizen nearby, move towards the citizen
        targetX = nearestCitizen->x;
        targetY = nearestCitizen->y;
    }
    move_direct(x,y,targetX,targetY,speed);
}

void Zombie::LayNhiem()
{
    for (int i = 0; i < Solider::soliders.size(); i++)
    {
        if (x == Solider::soliders[i]->x && y == Solider::soliders[i]->y)
        {
            string old_id = Solider::soliders[i]->ID;
            delete Solider::soliders[i];
            Solider::soliders.erase(Solider::soliders.begin() + i);
            Zombie* z = new Zombie;
            i--;
            z->ID = old_id;
            z->type = 3;
            z->x = x;
            z->y = y;
            z->speed = speed;
            zombies.push_back(z);
            return;
        }
    }
    for (int i = 0; i < Citizen::citizens.size(); i++)
    {
        if (x == Citizen::citizens[i]->x && y == Citizen::citizens[i]->y)
        {
            string old_id = Citizen::citizens[i]->ID;
            delete Citizen::citizens[i];
            Citizen::citizens.erase(Citizen::citizens.begin() + i);
            Zombie* z = new Zombie;
            z->ID = old_id;
            z->type = 3;
            z->x = x;
            z->y = y;
            z->speed = speed;
            zombies.push_back(z);
            return;
        }
    }
}

// Solider function 
void Solider::KillZombie()
{
    int count = 0;
    for (int i = 0; i < Zombie::zombies.size(); i++)
    {
        double dx = abs(x - Zombie::zombies[i]->x);
        double dy = abs(y - Zombie::zombies[i]->y);
        if (dx <= 1 && dy <= 1) // check if the zombie is within the 9 surrounding cells
        {
            count++;
            if (count > level) break; // stop killing zombies if the number of killed zombies is equal to the solider's level
            delete Zombie::zombies[i]; // delete the killed zombie
            Zombie::zombies.erase(Zombie::zombies.begin() + i);
            i--;
        }
    }
}


// Input function
Info * NhapThongTin()
{
    Info * info;
    string ID; int type;
    cin>> ID >> type;
        Solider* solider;
        Citizen* citizen;
        Zombie* zombie;
    switch (type)
    {
        case 1:
            info = new Solider;
            info->ID = ID;
            info->Nhap();
            solider = static_cast<Solider*>(info);
            Solider::soliders.push_back(solider);
            break;
        
        case 2:
            info = new Citizen;
            info->ID = ID;
            info->Nhap();
            citizen = static_cast<Citizen*>(info);
            Citizen::citizens.push_back(citizen);
            break;

        case 3:
            info = new Zombie;
            info->ID = ID;
            info->Nhap();
            zombie = static_cast<Zombie*>(info);
            Zombie::zombies.push_back(zombie);
            break;
    }
    return info;
}
// output function
bool cmp(Info* a, Info* b) {
    double dist_a = distance(a->x, a->y, 0, 0);
    double dist_b = distance(b->x, b->y, 0, 0);
    if (dist_a != dist_b) return dist_a < dist_b; else return a->ID < b->ID;
}

int main()
{
    int n;
    cin>>n;
    vector <Info*> info ;
    for (int i=0; i<n; i++) info.push_back(NhapThongTin());
    //stage 
while ((Zombie::zombies.size()!=0) && (Citizen::citizens.size()!=0 || Solider::soliders.size()!=0))
    {
        //Move
        for (auto& it: Citizen::citizens) { it->Move();}
        for (auto& it: Zombie::zombies)   { it->Move();}


        //Battle Stage;
        for (auto& it: Zombie::zombies)   {it->LayNhiem();}
        for (auto& it: Solider::soliders) { it->KillZombie();}
    }
    
    
    vector<Info*> result;
    if (Zombie::zombies.size()!=0) { for (auto it: Zombie::zombies) { result.push_back(it); } }
    if (Solider::soliders.size()!=0) { for (auto it: Solider::soliders) { result.push_back(it); }}
    if (Citizen::citizens.size()!=0) { for (auto it: Citizen::citizens) {  result.push_back(it);}}
    sort(result.begin(), result.end(),cmp);
    for (auto it: result) { it->Xuat();}
    abort();
    return 0;
}