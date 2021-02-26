#include"algorithm"
#include "iostream"

using namespace std;

int a[100000];
int l,n,k;

bool judge(int x){
    int k=0;
    for(int i=0;i<=n;i++){
        if((a[i+1]-a[i])>x)
        {
            k+=(a[i+1]-a[i])/x;
            if((a[i+1]-a[i])%x==0) k--;
        }
        if(k>k) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin>>l>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=0;a[n+1]=l;
    int left=0,r=10000000;
    while(left<r){
        int mid=(left+r)/2;
        if(judge(mid)) r=mid;
        else
        {
            left=mid+1;
        }
        // cout<<"l="<<left<<"right="<<r<<endl;
    }
    cout<<r;
    return 0;
}
