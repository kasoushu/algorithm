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

const int mm = 105;

int main(int argc, char *argv[])
{
    int sum =0,k,last=0;
    while(scanf("%d",&k)&&k!=0){
        if(last==1&&k==2){
            sum+=2;
        }
        if(last%2==0&&k==2){
            last+=2;
            sum+=last;
            continue;
        }
        if(k==1){
            sum+=1;    
        }
        last=k;
    }
    cout<<sum<<endl;
    return 0;
}
