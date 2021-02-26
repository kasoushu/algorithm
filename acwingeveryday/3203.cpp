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

const int mm = 105;

int n;
int a[mm][mm]={0};
int u1,u2;
int w1,w2;


int main(int argc, char *argv[])
{
    cin>>n;
    int cnt=0;
    for(int p=1;p<=n;p++){
        scanf("%d%d%d%d",&u1,&w1,&u2,&w2);
        for(int i=u1;i<=u2;i++){
            for(int j=w1;j<=w2;j++){
                if(!a[i][j]){
                    cnt++;
                    a[i][j]=1;
                }
            }}
    }
    cout<<cnt<<endl;
    return 0;
}
