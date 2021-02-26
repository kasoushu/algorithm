#include "iostream"
#include "algorithm"
#include "cstdio"

using namespace std;
//>fanhui false//<=fanhui true
int d,n,m;
int a[50005];
bool judge(int x){
    int sum=0;
    int now=0;
    for(int i=0;i<n+1;i++){
        if(a[i]-now<x) {sum++;}
        else
        {
            now=a[i];
        }
    }
    if(sum>m) return false;
    else
    {
        return true;
    }                   
}

int main(int argc, char const *argv[])
{
    cin>>d>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    a[n]=d;
    int l=0,r=d;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(judge(mid)) {l=mid+1;ans=mid;}
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
