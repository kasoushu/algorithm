#include "iostream"
#include "stdio.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int v[1000]={0},a[105];
    int n,count=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        if(v[a[i]]==0){
            count++;
            v[a[i]]=a[i];
        }
    }
    cout<<count<<endl;
    for(int i=0;i<1000;i++) if(v[i]>0){ cout<<v[i]<<' ';}
    return 0;
}
