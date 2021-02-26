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
using namespace std;

int main(int argc, char *argv[])
{
    int n,tot1=0,tot2=0;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(!(temp%2)){tot1++;temp/=2;}
        while(!(temp%5)){tot2++;temp/=5;}
        ans=ans*temp%10;
    }
    for(int i=0;i<tot1-tot2;i++) ans=ans*2%10;
    cout<<ans<<endl;
    return 0;
}
