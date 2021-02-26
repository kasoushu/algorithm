#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 2*(1e9)+10;
int n ;
bool a[mm];
void check(){
    for(int i=2;i<=mm;i++){
        for(int j=i;j<=mm;j+=i){
            a[i]=1;
        }
    }
}

int main(int argc, char *argv[])
{
    cin>>n;
    check();
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0&&!a[n/i]){
            return i;
        }
    }
    return 0;
}

