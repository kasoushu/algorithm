#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 1005;

struct edg{
    int u,v;
    double w;
}e[505*505];

int p,s,a[mm],b[mm],uu[mm];

int find(int x){return uu[x]==x?x:uu[x]==find(uu[x]);}

double cal(int x,int y,int i,int j){
    return sqrt((x-i)*(x-i)+(y-j)*(y-j));
}

int main(int argc, char *argv[])
{
    scanf("%d%d",&s,&p);
    int cnt=0;
    for(int i =1;i<=p;i++){
        scanf("%d%d",&a[i],&b[i]);
        for(int j=1;j<i;j++){
            cnt++;
            e[cnt].u = i;
            e[cnt].v=j;
            e[cnt].w=cal(a[i],a[j],b[i],b[j]);
        }
    }
    cout<<"hello";
    sort(e+1,e+cnt+1,[](edg x,edg y){
        return x.w<y.w;
            });
    int ans=0,j=1,lp=p;
    while(j<=cnt&&ans<p){
        int x = find(e[j].u),y=find(e[j].v);
        if(x!=y){
            uu[x]=uu[y];
            lp--;
            if(lp<=s){
                cout<<e[j].w<<endl;
                break;
                return 0;
            }
        }
    }
    return 0;
}
