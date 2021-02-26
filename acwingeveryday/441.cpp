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


int main(int argc, char *argv[])
{
    int l,r;
    cin>>l>>r;
    int cnt=0;
    for(int i=l;i<=r;i++){
        int k=i;
        while(k){
            if(k%10==2) cnt++;
            k/=10;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
