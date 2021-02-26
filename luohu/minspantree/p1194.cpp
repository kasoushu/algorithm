#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;
const int mm =50050;
struct edg{
    int u,v,w;
}e[mm];
int cnt=0;
void add_e(int u,int v,int w){
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
}

int a[mm],n,m;

int find(int x) {return a[x]==x?x:a[x]=find(a[x]);}

int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++) {
            int ww;
            scanf("%d",&ww); 
            if(ww>0){
                add_e(i, j, ww);
            }
        }
    }
    for(int i=1;i<=m;i++) {add_e(0, i, n);a[i]=i;}
    sort(e+1,e+1+cnt,[](edg q,edg w){
            return q.w<w.w;});
    int ans=0,j=1,cct=0;
    /* for(int i=1;i<=cnt;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl; */
    while(j<=cnt&&cct<=m){
        int x=find(e[j].u),y=find(e[j].v);
        if(x!=y){
            //cout<<"connect "<<x<<' '<<y<<endl;
            ans+=e[j].w;
            a[x]=y;
            cct++;
        }
        j++;
    }
    cout<<ans;
    return 0;
}
