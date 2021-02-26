#include "iostream"

using namespace std;
int n,r,w[1000],v[1000],dp[1000]={0};
int main(int argc, char const *argv[])
{
    cin>>r>>n;
    for(int i=0;i<n;i++) cin>>w[i]>>v[i];
    for(int i=0;i<n;i++){
        for(int l=w[i];l<=r;l++){
            dp[l]=max(dp[l],v[i]+dp[l-w[i]]);
        }
    }
    return 0;
}
