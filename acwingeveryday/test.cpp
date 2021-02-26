#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

const int mm = 100;
char c[mm];
int main(int argc, char *argv[])
{
    int n ;
    vector<int> a;
    for(int i =1;i<=n;i++){
        // scanf("%c",&c[i]);
        // cin>>c[i];
        a.push_back(i);
    }
    a.clear();
    cout<<a.size();
    return 0;
}
