#include "iostream"
#include "algorithm"
using namespace std;

int n;
long long c;
long long a[250000];
int main(int argc, char const *argv[])
{
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int k=0;
    for(int i=0;i<n;i++){
        int p=a[i]+c,l=i,r=n;
        if(a[(l+r)/2]>p) r=(l+r)/2-1;
        else l=(l+r)/2; 
        for(int j=l;j<r;j++){
            if(a[j]==p) k++;
        }
    }
    cout<<k;
    return 0;
}
