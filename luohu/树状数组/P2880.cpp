#include "bits/stdc++.h"
#define low_bit(x) (x&-x)
using namespace std;

int mx[100006],mi[100006];
int a[100005]={0};
int n;

void build(int i,int v){
    for(int k=i;k<=n;k+=low_bit(k)){
        mx[k]=max(mx[k],v);
        mi[k]=min(mi[k],v);
    }
}

int query_mx(int l,int r){
    if(l<r){
        if(r-low_bit(r)>l) return max(mx[r],query_mx(l,r-low_bit(r)));
        else return max(a[r],query_mx(l,r-1));
    }
    return a[l];
}

int query_mi(int l,int r){
    if(l<r){
        if(r-low_bit(r)>l) return min(mi[r],query_mi(l,r-low_bit(r)));
        else return min(a[r],query_mi(l,r-1));
    }
    return a[l];
}


int main(int argc, char const *argv[])
{
    int q;
    cin>>n>>q;
    memset(mi,0x3f3f3f3f,sizeof(mi));
    memset(mx,0,sizeof(mx));

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        build(i,a[i]);
        // for(int i=1;i<=n;i++) {
        //     cout<<mx[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=1;i<=n;i++) {
        //     cout<<mi[i]<<' ';
        // }
        // cout<<endl;
    }
    int l,r;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l,&r);
        // cout<<query_mx(l,r)<<' '<<query_mi(l,r)<<endl;
        printf("%d\n",query_mx(l,r)-query_mi(l,r));
    }

    return 0;
}
