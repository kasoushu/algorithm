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

int n,a[105][105];

int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    while(n){
        for(int i=1;i<=n;i++){
            a[i][1]=i;
            a[1][i]=i;
        }

        for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                a[i][j]=a[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",a[i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
        scanf("%d",&n);
    }

    return 0;
}
