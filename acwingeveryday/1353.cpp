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
using namespace std;

const int mm = 1050;

int n,a[mm];

int main(int argc, char *argv[])
{
    int ans=INF;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=0;i<=84;i++){
        int l=i,r=l+17,now=0;
        for(int k=1;k<n;k++){
            if(a[k]<l) now+=(a[k]-l)*(a[k]-l);
            if(a[k]>r) now+=(a[k]-r)*(a[k]-r);
        }
        ans=min(ans,now);
    }

    cout<<ans;
    return 0;
}
