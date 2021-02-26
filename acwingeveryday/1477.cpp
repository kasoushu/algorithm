#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <string>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

int n;
string k[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(int argc, char *argv[])
{
    cin>>n;
    int ans=0;
    while(n){
        ans+=(n%10);
        n/=10;
    }
    string s = to_string(ans);
    for(auto &j:s){
        cout<<k[j-'0']<<' ';
    }

    return 0;
}
