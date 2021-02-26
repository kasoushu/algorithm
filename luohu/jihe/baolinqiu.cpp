#include "iostream"
#include "map"
using namespace std;
// int a[10000000];
map<int,int> a;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        a[k]=i;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int l;
        cin>>l;
        cout<<a[l]<<endl;
    }
    return 0;
}
