#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 100004;

int a[mm]={0};

/* int main(int argc, char *argv[])
 * {
 *     int n,m;
 *     cin>>n>>m;
 *     for(int i=1;i<=m;i++){
 *         int x,y;
 *         scanf("%d%d",&x,&y);
 *         for(int j=x;j<=y;j++){
 *             a[j]=1;
 *         }
 *     }
 *     int ans=0;
 *     for(int i=0;i<=n;i++){
 *         if(a[i]==0) ans++;
 *     }
 *     cout<<ans<<endl;
 *
 *     return 0;
 * } */
int main(int argc, char *argv[])
{
    pair<int, int> b[2000];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&b[i].first,&b[i].second);
    }
    sort(b+1,b+1+m);
    int beg=b[1].first,end=b[1].second;
    int res=0;
    for(int i=2;i<=m;i++){
        if(end>b[i].first) end=max(end,b[i].second);
        else{
            res+=end-beg+1;
            beg=b[i].first;
            end=b[i].second;
        }
    }
    res+=end-beg+1;
    cout<<1+n-res;
    return 0;
}
