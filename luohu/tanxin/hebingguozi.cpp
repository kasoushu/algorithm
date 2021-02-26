#include "iostream"
#include "algorithm"

using namespace std;

int a[10005]={0};
int n,sum=0;

void result(){
    sort(a,a+n);
    // int l=0;
    for (int i = 0;i<n-1; i++){
        sum+=a[i]+a[i+1];
        a[i]+=a[i+1];
        for (int j=i+1; j <n;j++)
        {
            if (a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }else {
                break;}
        }
        
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    // int *a=new int[n]();
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    result();
    cout<<sum;
    // delete []a;
    return 0;
}
