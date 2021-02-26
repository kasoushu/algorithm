#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define LL long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 50050;

struct node{
    int w,s;
}a[mm];
int n;


int main(int argc, char *argv[])
{
    cin>>n;
    for(int i =1 ;i <=n;i++){
        scanf("%d%d",&a[i].w,&a[i].s);
    }
    sort(a+1,a+1+n,[](node x,node y){
            return x.w+x.s<y.w+y.s;
            });
    LL ans =0,sum=0;
    sum = a[1].w;
    for(int i =2 ;i<=n;i++){
        ans+=max(sum-a[i].s,0);
        sum+=a[i].w;
    }
    cout<<ans<<endl;
    return 0;
}
