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

const int mm = 1005;
int n;
int a[mm];
int main(int argc, char *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0;
    for(int i=2;i<=n-1;i++){

        if(a[i]>a[i-1]&&a[i]>a[i+1]) cnt++;
        if(a[i]<a[i-1]&&a[i]<a[i+1]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
