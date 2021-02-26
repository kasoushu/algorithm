#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int n,m,a[100006][3];
int cnt[100006]={0};
int last,p;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    scanf("%d",&last);
    //a[i]表示a[i] i->i+1,i=1...n;    
    for(int i=2;i<=m;i++){
        scanf("%d",&p);
        int mm=last<p?p:last;
        int mx=last<p?last:p;
        cnt[mx]++;cnt[mm]--;
        last=p;
    }
    for(int i=1;i<=n-1;i++){
        // int x,y,z;
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    // for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";//cnt[i]表示 乘坐i->i+1这段路线的次数,a[i]表示i->i+1路线的车费
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=cnt[i];
        ans+=min(a[i][0]*sum,sum*a[i][1]+a[i][2]);
        cout<<sum<<' '<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
