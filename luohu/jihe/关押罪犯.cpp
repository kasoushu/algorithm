#include "iostream"
#include "bits/stdc++.h"
#include "algorithm"
using namespace std;
typedef struct 
{   
    int x,y,w;
}node;

node p[100005];
int f[20005],en[20005];

int find(int k){
    if(k==f[k]) return k;
    return f[k]=find(f[k]);
}
void union_set(int x,int y){
    int a=find(x),b=find(y);
    f[a]=b;
}
bool check(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return true;
    return false;
}
bool cmp(node a,node b){
    return a.w>b.w;
}
int n,m;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>p[i].x>>p[i].y>>p[i].w;
    }
    for(int i=0;i<=n;i++) f[i]=i;
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m+1;i++){
        if(check(p[i].x,p[i].y)){ printf("%d",p[i].w); return 0;}
        else{
        if(!en[p[i].x]) en[p[i].x]=p[i].y;
        else
        {
            union_set(en[p[i].x],p[i].y);
        }
        if(!en[p[i].y]) en[p[i].y]=p[i].x;
        else
        {
            union_set(en[p[i].y],p[i].x);
        }
        }

    }
    cout<<0;
    return 0;
}
