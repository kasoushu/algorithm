#include "iostream"
#include "algorithm"

using namespace std;

int n,m;
int a[1000005];

bool judge(long long x){
    long long sum=0;
    int time=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]<=x)sum+=a[i];
        else{
            time++;
            sum=a[i];
        }
    }
    return time>=m;
    
}

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    long long l=0,r=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        r+=a[i];
        l=l>a[i]?l:a[i];
        }
    long long ans=0;
    while(l<=r){
        long long  mid=(l+r)/2;
        if(judge(mid)){l=mid+1;ans=mid;}
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
