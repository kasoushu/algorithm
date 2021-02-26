#include "bits/stdc++.h"
#include "algorithm"
#define ll long long

using namespace std;

struct node{
    ll l,r;
}a[10000];


bool cmp(node x,node y){
    return x.l<y.l||(x.l==y.l&&x.r<y.r);
}
ll n;




int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+n+1,cmp);
    a[n+1].l=0x7fffffff;
    ll ans=0;
    int sta=a[1].l,end=a[1].r;
    for(int i=1;i<=n;i++){
        if(end<=a[i+1].l){
            ans+=end-sta,sta=a[i+1].l,end=a[i+1].r;
        }
        else if(end>a[i+1].l){
            end=end>a[i+1].r?end:a[i+1].r;
        }
    }
    cout<<ans;
    return 0;
}
