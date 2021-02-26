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

const int mm = 1e5+50;

int n,k,a[mm],sum[mm],res[mm],ans=0;

int main(int argc, char *argv[])
{
    cin>>n>>k;
    for(int i =1 ;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=(sum[i-1]+a[i])%k;
        ans+=res[sum[i]];
        res[sum[i]]++;
    }
    cout<<ans+res[0]<<endl;
    return 0;
}
