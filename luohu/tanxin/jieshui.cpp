#include "algorithm"
#include "iostream"
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    pair<int,int> *a=new pair<int,int>[n];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<a[i].second<<' ';
        sum+=a[i].first*(n-i-1);
    }
    cout<<endl<<sum;
    return 0;
}
