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

const int mm = 30005;
struct node{
    int w,v;
}a[mm];
int n,m;
int dp[mm];
int main(int argc, char *argv[])
{
    cin>>m>>n;
    for(int i =1 ;i <= n; i++){
        scanf("%i%d",&a[i].w,&a[i].v);
    }
    sort(a+1,a+1+n,[](node x,node y ){
            return x.w/x.v < y.w/y.v;
            });
    // for(int i =1 ;i<=n;i++){
    //     cout<<a[i].w<<' '<<a[i].v<<endl;
    // }
    for(int i =1 ;i<=n;i++){
        for(int j = m;j>=a[i].w;j--){
            dp[j] = max(dp[j],dp[j-a[i].w]+a[i].w*a[i].v);
        }
    }
    cout<<dp[m];
    return 0;
}
