#include "stdio.h"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
    int h[10000]={6,2,5,5,4,5,6,3,7,6,0},n,count=0;
    cin>>n;
    for (int i = 10; i <10000; i++){
        int x=i/10,y=i%10;
        h[i]=h[x]+h[y];
    }
    n-=4;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if(h[i]+h[j]+h[i+j]==n) count++;
        }
    }
    cout<<count;
    return 0;
}
