#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int mn = 100006;
int a[mn],b[mn];
int n,m;

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
    double l=0,r=0x3f3f3f3f;
    double mid;
    while(r-l>0.001){
        mid=(l+r)/2;
        int k=0;
        for(int i=1;i<=n;i++){
            k+=(int)(a[i]/mid);
        }
        if(k>=m){
            l=mid;
        }else if(k<m){
            r=mid;
        }
        // cout<<l<<' '<<r<<' '<<mid<<' '<<k<<endl;
    }
    printf("%.2f",mid);
    return 0;
}
