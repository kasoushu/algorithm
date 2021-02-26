#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;
const int mm = 10005;
const int mn = 1005;
struct edge{
    int u,v,w;
}e[mm];
int h[mm],cnt=0;


int n,m,k,a[mn],ans=0;

int find(int x){return a[x]==x?x:a[x]=find(a[x]);}

int main(int argc, char *argv[])
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+m+1,[](edge i,edge j){
        return i.w<j.w;
            });
    for(int i=1;i<=n;i++) a[i]=i;
    //for(int i=1;i<=m;i++) {cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;}
    cnt=n;
    for(int i=1;cnt>k&&i<=m;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){
            a[x]=y;
            ans+=e[i].w;
            cnt--;
        }
    }
    if(cnt>k) cout<<"No Answer"<<endl;
    else cout<<ans<<endl;
    return 0;
}
