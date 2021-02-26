#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 200050;

struct node{
    int w,v;
}a[mm];
int l,r,n,m,S;
PII b[mm];

int get_y(int w){
    int sum[mm],cnt[mm];
    for(int i =1 ;i<=n;i++){
        if(a[i].w>=w){
            sum[i]=sum[i-1]+a[i];
            cnt[i] = cnt[i-1]+1;
        }else{
            sum[i]=sum[i-1];
            cnt[i]=cnt[i-1];
        }
    }
    int res = 0 ;
    for(int i =1 ;i<=m;i++){
        int l =b[i].first, r = b[i].second;
        res+=(cnt[r]-cnt[l-1])*(sum[r]-sum[l-1]);
    }
    return res;
}

int main(int argc, char *argv[])
{
    cin>>n>>m>>S;
    for(int i =1 ;i <=n ; i++){
        scanf("%d%d",&a[i].w,&a[i].v);
    }
    for(int i =1 ;i<=m;i++) {
        scanf("%d%d",&b[i].first,&b[i].second);
    }
    int l = 0, r = 0x3f3f3f3f;
    while(l<r){
        int mid = (l+r)>>1;
        int res = get_y(mid);
        if(res>=S) l=mid;
        else{
            r=mid;
        }
    }
    cout<<min(get_y(r),get_y(r+1));
    return 0;
}
