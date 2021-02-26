#include "stdio.h"
#include "iostream"

using namespace std;

int prime[10000000],a,b;

void get_prime(int n){
    for(int i=0;i<=n;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i = 2; i <=n; i++){
        if (!prime[i]) continue;
        for(int j=i*2;j<=n;j+=i) { prime[j]=0;}
    }
    
}

bool is_plindrome(int n){
    int y=n,sum=0;
    while (y)  {
        sum=sum*10+y%10;
        y/=10;
    }
    if(n==sum) return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    cin>>a>>b;
    if(b>=10000000) b=9999999;
    get_prime(b);
    for(int i=a;i<=b;i++)
        if (is_plindrome(i)){
            if (prime[i]==1) cout<<i<<endl;
        }
    return 0;
}

