#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int a[200005];
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int k;
    for (int i = 0; i < m; i++)
    {
        cin>>k;
        cout<<a[k-1]<<endl;
    }
    
    
    return 0;
}
