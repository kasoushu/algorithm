#include "bits/stdc++.h"
#include "algorithm"
using namespace std;

const int CN=4e6+6;

int read(){
    int s=0,ne=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')ne=-1;
    for(;c>='0'&&c<='9';c=getchar()) s=(s<<1)+(s<<3)+c-'0';
    return s*ne;
}

int n;
class locat{
    public:int x,y;
    bool operator < (const locat &a) const{
        if(x==a.x) return y<a.y;
        return x<a.x;
    }
}ans[CN];
int acnt=0;


class Sugment{
    public:int r,x,k;
    bool operator <(const Sugment &a)const{
        return x<a.x;
    }
}sug[CN];
int scnt=0;
int pos[CN],pcnt;
class node{
    public:int len,cnt;
};

class SGT{
    public:
    node d[CN<<2];
    int Getlen(int l,int r,int k){
        if(d[k].cnt) return pos[r+1]-pos[l];
        if(l==r) return 0;
        return d[k<<1].len+d[k<<1|1].len;
    }
    void modify(int l,int r,int k,int s,int t,int x){
        if(s<=1&&r<=t){
            d[k].cnt+=x;
            d[k].len=Getlen(l,r,k);
            return ;
        }
        int m=(l+r)>>1;
        if(s<=m)modify(l,m,k<<1,s,t,x);
        if(m<t) modify(m+1,r,k<<1|1,s,t,x);
        d[k].len=Getlen(l,r,k);
    }
}sgt;

void SugmentCover(int i){
    int l=1;
    int r=lower_bound(pos+1,pos+pcnt+1,sug[i].r)-pos-1;
    sgt.modify(1,pcnt,1,l,r,sug[i].k);
}


int main(int argc, char const *argv[])
{
    n=0;
    int x,y,z;
    while(~scanf("%d%d%d",&x,&y,&z)){
        n++;
        sug[scnt+1].r=y;sug[scnt+1].x=x;sug[scnt+1].k=1;
        sug[scnt+2].r=y;sug[scnt+2].x=z;sug[scnt+2].k=-1;
        scnt+=2;
        pos[n]=y;
    }
    pos[++n]=0;
    sort(sug+1,sug+scnt+1);
    sort(pos+1,pos+n+1);
    pcnt=1;
    for(int i=2;i<=n;i++){
        if(pos[i]!=pos[i-1])pos[++pcnt]=pos[i];
    }
    int prvh=0;
    for(int i=1;i<=scnt;i++){
        while (sug[i].x==sug[i+1].x&&i<scnt)
        {
            SugmentCover(i),i++;
        }
        SugmentCover(i);
        if(sgt.d[1].len!=prvh){
            ans[++acnt].x=sug[i].x;
            ans[acnt].y=prvh;
            prvh=sgt.d[1].len;
            ans[++acnt].x=sug[i].x;
            ans[acnt].y=prvh;
        }        
    }
    for(int i=1;i<=acnt;i++)
        if(i&1) printf("%d",ans[i].x);
        else printf("%d",ans[i].y);
    return 0;
}
