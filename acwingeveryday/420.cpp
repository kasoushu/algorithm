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
using namespace std;

const int mm = 10050;
int a[mm],n,m;

int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(m--) next_permutation(a+1,a+1+n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
