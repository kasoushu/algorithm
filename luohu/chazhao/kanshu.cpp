#include "iostream"
#include "algorithm"

using namespace std;

long long  n,sum;
long long a[1000005];
int main(int argc, char const *argv[])
{
    cin>>n>>sum;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long high=a[n],left=a[1],right=a[n];
    // long long p_sum=0;
    while(left<=right){
        long long now_sum=0;
        long long mid=(left+right)/2;
        // cout<<"mid="<<mid;
        for(int i=n;i>0;i--){
            if(a[i]>mid) {now_sum+=a[i]-mid;}
        }
        // cout<<now_sum<<endl;
        if(now_sum<sum) right=mid-1 ;
        if(now_sum>=sum) left=mid+1;
    }
    cout<<(left+right)/2;
    return 0;
}
