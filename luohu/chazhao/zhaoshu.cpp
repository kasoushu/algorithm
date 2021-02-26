#include "iostream"

using namespace std;
int n,m;
long long a[100005];

int two_find(long long p,int left,int right){
    if(left>right) return -1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==p) {
            int l=mid;
            while(a[l-1]==p) l--;
            return l;
        }
        else if(a[mid]>p) right=mid-1;
        else {
            left=mid+1;
        }
    }
    if(a[right]!=p) return -1;
}

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        long long now;
        cin>>now;
        cout<<two_find(now,1,n)<<' ';
    }
    return 0;
}
