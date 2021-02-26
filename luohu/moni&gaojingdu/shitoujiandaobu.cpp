#include "stdio.h"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
    int win[5][5]={{2,1,0,0,1},{0,2,1,0,1},{1,0,2,1,0},{1,1,0,2,0},{0,0,1,1,2}};
    int n,c1,c2,count1,count2;
    int a[201],b[201];
    cin>>n>>c1>>c2;
    for (int i = 0; i <c1; i++) cin>>a[i];
    for (int i = 0; i <c2; i++) cin>>b[i];
    for (int i = 0; i < n; i++)
    {
        if (win[a[i%c1]][b[i%c2]]==1) count1++;
        if (win[a[i%c1]][b[i%c2]]==0) count2++;
    }
    cout<<count1<<" "<<count2<<endl;
    
    
    return 0;
}
