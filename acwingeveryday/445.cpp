#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;


int main(int argc, char *argv[])
{
    string a;
    char c;
    int flag=1;
    cin>>c;
    cin>>a;
    reverse(a.begin(), a.end());
    int l=0;
    while(a[l]=='0') l++;
    a=a.substr(l,a.size()-l+1);
    if(c>='0'&&c<='9') a=a+c;
    else{
        a=c+a;
    }
    cout<<a<<endl;
    return 0;
}
