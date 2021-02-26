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

const int mm = 100050;
int c[mm],a[mm],ave=0;
int n;
int main(int argc, char *argv[])
{
    cin>>n;
    int sum  = 0;
    for(int i =1 ;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ave = sum/n;
    for(int i =1 ;i<=n;i++){
        c[i] = c[i-1] + a[i] -ave;
    }
    sort(c+1,c+1+n);
    int k = c[n/2+1];
    int ans =0 ;
    for(int i =1 ;i<=n;i++){
        ans+=abs(c[i]-k);
    }
    cout<<ans<<endl;
    return 0;
}
