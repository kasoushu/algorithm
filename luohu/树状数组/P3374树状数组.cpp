#include "iostream"
#include "bits/stdc++.h"
#include "algorithm"
#define ll long long
#define NN 500005
#define low_bit(x) ((x)&(-x))
using namespace std;

ll n,q;
ll a[NN];

void update(int pos,int v){
    for(int i=pos;i<=n;i+=low_bit(i)){
        a[i]+=v;
    }
}
ll query(int r){
    ll res=0;
    for(int i=r;i;i-=low_bit(i)) res+=a[i];
    return res;
}

int main(int argc, char const *argv[])
{
    cin>>n>>q;
    int x;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>x;
        update(i,x);
    }
    for(int i=0;i<q;i++){
        int x,y,z;
        cin>>x;
        if(x==1){
            cin>>y>>z;
            update(y,z);
        }
        else if(x==2){
            cin>>y>>z;
            cout<<query(z)-query(y-1)<<endl;
        }
    }
    return 0;
}
