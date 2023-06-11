#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MaxN 10000
int n, a[MaxN], q;

int Search(int left, int right, int x){
    if (right >= left)  {
         int mid = left + (right - left) / 2;
    if (a[mid] == x) {
            return mid;
                     }
        if (a[mid] > x) {
            return Search( left, mid - 1, x);
                        }
           return Search( mid + 1, right, x);
                         }
    return -1;
}

int main()
{
    int x;
    cin >> n;
    cin >> q;
    for (int i =0; i< n; i++) cin >> a[i];
    for (int i =1; i<=q; i++)
    {
        cin >> x;   
        if (Search(0,n-1,x) ==-1) cout<<("NO"); else cout<<("YES");
        if (i!=q) cout<<endl;
    }
    return(0);
}