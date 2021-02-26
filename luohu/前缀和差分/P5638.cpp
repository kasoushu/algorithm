#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1000000],f[100000]={0};
int main(int argc, char const *argv[])
{
    cin>>n>>k;
    for(int i=1;i<n;i++){scanf("%lld",&a[i]);f[i]=f[i-1]+a[i];}
    // max=max(f[i+k]-f[i]);
    ll mm=f[k];
    for(int i=1;i+k<n;i++){
        mm=max(mm,f[i+k]-f[i]);
    }
    cout<<f[n-1]-mm;
    return 0;
}
