#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 8000;
int a[mm],dp[mm][2]={0}; // 1 come 0 don't come
int e[mm],nex[mm],h[mm],cnt=0;
int n,vis[mm]={0},is_lead[mm]={0};

void add_edge(int u,int v){
    e[++cnt] = v;
    nex[cnt] = h[u];
    h[u]=cnt;
}

void get_ans(int root){
   vis[root]=1;
   for(int i=h[root];i;i=nex[i]){
        if(vis[e[i]]) continue;
        get_ans(e[i]);
        /* cout<<"circle"<<root<<' '; */
        dp[root][1]+=dp[e[i]][0];
        dp[root][0]+=max(dp[e[i]][0],dp[e[i]][1]);
   }
}

int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i][1] = a[i];
    }
    int x,y,ans=0;
    
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        is_lead[x]=1;
        add_edge(y, x);
    }
    for(int i=1;i<=n;i++){
        if(!is_lead[i]){
            get_ans(i);
            /* cout<<max(dp[i][0],dp[i][1])<<' '<<"leader is "<<i<<endl; */
            ans=max(ans,max(dp[i][1],dp[i][0]));
        }
    }
    cout<<ans<<endl;
    return 0;
}
