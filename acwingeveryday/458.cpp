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
    int A,B,L;
    int a,b,mmi=1e9;
    for(int i=0;i<=L;i++){
        for(int j=0;j<=L;j++){
            double x1 = (double)i/j;
            double x2 = (double)A/B;
            if(x1>x2&&x1<mmi){
                a=i,b=j;
                mmi=x1;
            }
        }
    }
    cout<<a<<endl<<b<<endl;
    return 0;
}

