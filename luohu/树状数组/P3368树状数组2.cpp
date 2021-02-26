#include "iostream"
#include "bits/stdc++.h"
#include "algorithm"
#define ll long long
#define NN 500005
#define low_bit(x) ((x)&(-x))
using namespace std;

ll n,q;
ll a[NN],b[NN];

void update(int j,int v){

    for(int i=j;i<=n;i+=low_bit(i)){
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
        cin>>b[i];
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(x==1){
            int l,r,z;
            cin>>l>>r>>z;
            update(l,z);
            update(r+1,-z);
        }
        else if(x==2){
            // for(int l=1;l<=n;l++) cout<<a[l]<<' ';
            // cout<<endl<<"query: ";
            int z;
            cin>>z;
            cout<<query(z)+b[z]<<endl;
        }
    }
    return 0;
}
