#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#include <utility>
#include <vector>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;
const int mm = 50006;
struct edg{
    int u,v,w;
}e[mm];



int a[mm],n,m,s,t,cnt=0;
int find(int x) {return a[x]==x?x:a[x]=find(a[x]);}
void add(int u,int v,int w){ e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;}

int main(int argc, char *argv[])
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y, x, z);
    }
    for(int i=1;i<=n;i++) a[i]=i;
    sort(e+1,e+1+cnt,[](edg i,edg j){return i.w<j.w;});
    // for(int i=1;i<=cnt;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
    int ans=0,cct=0,j=1;
    while(j<=cnt&&cct<n){
        int x=find(e[j].u),y=find(e[j].v);
        if(x!=y){
            a[x]=y;
            cct++;
        }
        if(find(s)==find(t)){
            cout<<e[j].w;
            return 0;
        }
        j++;
    }
    return 0;
}
