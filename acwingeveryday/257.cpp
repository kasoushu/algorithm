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
#define PII pair<int,int> 
using namespace std;

const int mm = 20005;
const int mn = 100005;

struct node{
    int x,y,w;
}nod[mm];

int f[mm*2],a[mn],en[mm];
int n,m;

int find(int x) { return f[x]==x?x:f[x]=find(f[x]);}
void uni(int x,int y){x=find(x),y=find(y),f[x]=y;}
// bool check(int x,int y){x=find(x),y=find(y);return x==y?1:0;}


int main(int argc, char *argv[])
{
    memset(en,0,sizeof(en));
    cin>>n>>m;
    for(int i =1 ;i<=m;i++){
        scanf("%d%d%d",&nod[i].x,&nod[i].y,&nod[i].w);
    }
    sort(nod+1,nod+1+m,[](node x,node y){
        return x.w>y.w;
            });
    for(int i =1 ;i<=n*2;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int x=nod[i].x,y=nod[i].y,w=nod[i].w;
        if(find(x)==find(y)) {cout<<w<<endl;return 0;}
        else {
            if(!en[x]) en[x]=y;
            else{
                uni(en[x],y);
            }
            if(!en[y]) en[y]=x;
            else{
                uni(en[y],x);
            }
            }
    }
    cout<<0<<endl;
    return 0;
}
