#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define LL long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

int mod ;
int a,b;
int ans =1;
LL qpow(int a,int b){
    if(b==0) return 1;
    if(b&1){
        return (qpow(a,b-1)*a)%mod;
    }else{
        return ((qpow(a,b/2))%mod*(qpow(a,b/2)%mod))%mod;
    }

}



int main(int argc, char *argv[])
{
    cin>>a>>b>>mod;
    cout<<qpow(a,b);
    return 0;
}

