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
#define PII pair<int,int> 
using namespace std;

const int mm = 100050;

int a[mm],n,l,r;

bool check(int k){
    int E=k;
    for(int i=1;i<=n;i++){
        if(a[i]>E) E-=(a[i]-E);
        if(a[i]<E) E+=(E-a[i]);
        if(E<0) return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    l=0,r=mm;
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<(l+r)/2;
    return 0;
}
