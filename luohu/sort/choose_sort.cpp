#include "stdio.h"
#include "iostream"

using namespace std;

void sort_print(int  a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

void choose_sort(int a[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int t=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[t]) t=j;
        }
        if (t!=i){
            int temp=a[i];
            a[i]=a[t];
            a[t]=temp;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int a[]={1,4,8,5,2};
    choose_sort(a,5);
    sort_print(a,5);
    return 0;
}
