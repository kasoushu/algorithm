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

const int mm = 1e5+50;

int a[mm],n;
int ans1,ans2,s1=0,s2;
int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s1+=a[i];
    }
    sort(a+1,a+1+n);
    s2=n;
    ans2=0;
    for(int i=1;i<=n/2;i++){
        ans2+=a[i];
    }
    ans1=n-n/2-n/2;
    cout<<ans1<<' '<<s1-ans2*2<<endl;
    return 0;
}
