#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <climits>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 1000050;

int n,m,d[mm*8],lazy[mm*8],a[mm];


void down(int p){
    if(lazy[p]){
        d[p<<1] -= lazy[p];
        d[(p<<1)| 1] -= lazy[p];
        lazy[p<<1] += lazy[p];
        lazy[(p<<1)|1] += lazy[p];
        lazy[p] = 0;
    }
}

void build(int p,int l,int r){
    if(l==r){
        d[p] = a[r];
        return ;
    }
    int mid = (l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    d[p] = min(d[p<<1],d[(p<<1)|1]);
}

int query(int p,int l,int r,int ql,int qr){
    down(p);
    if(l>=ql&&r<=qr){
        return d[p];
    }
    int mid = (l+r)>>1,ans=INT_MAX;
    if(ql<=mid) ans = min(ans,query(p<<1, l, mid, ql, qr));
    if(qr>mid)  ans = min(ans,query((p<<1)|1, mid+1, r, ql, qr));
    d[p] = min(d[p<<1],d[(p<<1)|1]);
    return ans;
}

void update(int p ,int l ,int r ,int ul,int ur,int k ){
    down(p);
    if(ul<=l&&ur>=r){
        d[p] -= k;
        lazy[p] +=k;
        return;
    }
    int mid =(l+r)>>1;
    if (ul<=mid) update(p<<1, l, mid, ul, ur, k);
    if(mid<ur) update(p<<1 |1,mid+1,r,ul,ur,k);
    d[p] = min(d[p<<1],d[p<<1 | 1 ]);
}


int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i = 1 ;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1, 1, n);
    for(int i =1 ;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int K = query(1, 1, n, y, z);
        if(K>=x){
            update(1, 1, n, y, z, x);
        }else{
            puts("-1");
            cout<<i<<endl;
            return 0;
        }
    }
    puts("0");
    return 0;
}

