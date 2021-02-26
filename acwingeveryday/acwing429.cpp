#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 500;

struct stu{
    int num,x,y,z,tot;
}a[mm];

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        a[i].num=i;
        a[i].tot=a[i].x+a[i].y+a[i].z;
    }
    sort(a+1,a+1+n,[](stu i,stu j){
        if(i.tot==j.tot){
            if(i.x==j.x){return i.num<j.num;}
            return i.x>j.x;
        }
        return i.tot>j.tot;
            });

    for(int i=1;i<=5;i++){
        cout<<a[i].num<<' '<<a[i].tot<<endl;
    }
    return 0;
}
