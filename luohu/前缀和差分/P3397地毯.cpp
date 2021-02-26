#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int x1,x2,y1,y2;
    int a[1005][1005]={0};   
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int j=x1;j<=x2;j++){
            a[j][y1]++;
            a[j][y2+1]--;
        }
    }
    int sum=0;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n+1;j++){
            sum+=a[i][j];
            printf("%d ",sum);
        }
        cout<<endl;
    }
    return 0;
}
