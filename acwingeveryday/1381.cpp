#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;

int n,m;
int a[10005];
ll b[10005]={0};
int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    b[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=m;j++){
            b[j]+=b[j-a[i]];
        }
    }
    cout<<b[m];
    return 0;
}
