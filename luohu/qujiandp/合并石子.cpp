#include "iostream"

using namespace std;

int n;
int dp_min[300][300]={0},dp_max[300][300],sum[300]={0},a[300];

int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        a[i]=k;a[n+i]=k;sum[i]=sum[i-1]+k;
    }
    for(int i=n+1;i<=2*n;i++) {sum[i]=sum[i-1]+a[i];}
    
    
    for (int len = 1; len < n; len++){
        for(int i=1;i<=2*n-1;i++){
            int j=i+len;
            dp_min[i][j]=0x7fffffff;
            for(int k=i;k<=2*n-1&&k<j;k++){
                dp_max[i][j]=max(dp_max[i][j],dp_max[i][k]+dp_max[k+1][j]+sum[j]-sum[i-1]);
                dp_min[i][j]=min(dp_min[i][j],dp_min[i][k]+dp_min[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    int ans_max=0,ans_min=0x7fffffff;
    for(int i=1;i<=n;i++){
        ans_max=max(ans_max,dp_max[i][i+n-1]);
        ans_min=min(ans_min,dp_min[i][i+n-1]);
    }
    cout<<ans_min<<endl<<ans_max<<endl;
    return 0;
}