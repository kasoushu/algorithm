#include <iostream> 
#include <algorithm> 
#include <vector>
 
using  namespace std;
 
int a[100005];
long long k,n;
int main(int argc, char const *argv[])
{
    cin>>n>>k;
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    int l=0,r=a[n-1];
    while(l+1<r){
        int mid=(l+r)/2;
        long long now_k=0;
        for (int i = n-1; i >=0; i--)
        {
            now_k+=a[i]/mid;
        }
        if(now_k>k) {l=mid;break;}
        else if(now_k<=k){ r=mid;}
        // if(now_k==k) {cout<<mid;return 0;}
        // cout<<"k="<<now_k<<' '<<mid<<' '<<l<<' '<<r<<endl;
    }
    cout<<r;
    return 0;
}