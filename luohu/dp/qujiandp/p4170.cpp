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

const int mm = 200;
int n;
int dp[mm][mm];
string st;



int main(int argc, char *argv[])
{
    cin>>st;
    n = st.size();
    memset(dp,INF,sizeof(dp));
    for(int i=0;i<=n;i++){dp[i][i]=1;}
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            if(st[i-1]==st[j-1]){
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
            }else{
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]); 
                    /* cout<<123<<endl; */
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<dp[i][n]<<' ';
    cout<<dp[1][n];
    return 0;
}
