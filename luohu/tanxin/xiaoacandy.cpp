#include "iostream"
#include "algorithm"
using namespace std;
int n,x;
int re(int a[],int n){
    long long sum=0;
    // cout<<0;
    if(a[0]>x){ sum+=a[0]-x;a[0]=x;}
    // cout<<1;
    for(int i=0;i+1<n;i++){
        // cout<<3;
        if(a[i]+a[i+1]>x){
            sum+=a[i]+a[i+1]-x;
            // cout<<sum<<' ';
            a[i+1]=x-a[i];
        }
    }
    // cout<<2;
    return sum;
}


int main(int argc, char const *argv[])
{
    // cout<<2032;
    int a[10005]={0};
    // int n,x;
    cin>>n>>x;
    // cout<<12;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // cout<<00;
    // sort(a,a+n);//不能排序，排序后和原来的序列不一致
    cout<<re(a,n);
    return 0;
}
