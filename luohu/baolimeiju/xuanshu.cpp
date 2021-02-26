#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;
int n=0,a[20],k;
bool isprime(int n){
    int k=sqrt(n);
    for (int i =2; i <=k; i++) if(n%i==0) return 0;
    return true;
}
int getsum(int already_sum,int now_k,int start,int end){
    if(now_k==0) return isprime(already_sum);
    int sum=0;
    for(int i=start;i<=end;i++){
        sum+=getsum(already_sum+a[i],now_k-1,i+1,end);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<getsum(0,k,0,n-1);
    return 0;
}
