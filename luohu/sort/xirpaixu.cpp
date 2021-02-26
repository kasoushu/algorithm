#include "stdio.h"
#include "iostream"

using namespace std;

void sort_print(int  a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

void sort_swap(int x[],int a,int b){
    int temp=x[a];
    x[a]=x[b];
    x[b]=temp;
}
void xier_sort(int a[],int n){
    for (int gap = n/2; gap>=1; gap/=2)
    {
        for ( int i = gap; i < n; i++)
        {
            for (int j = i; j < n; j+=gap)
            {
                int now=a[j],k;
                for ( k = j-gap; k>=0&&a[k]>now; k-=gap)
                {
                    a[k+gap]=a[k];
                    // sort_swap(a,k,k+gap);
                }
                a[k+gap]=now;
                sort_print(a,5);  
            }
            
        }

    }
    
}
int main(int argc, char const *argv[])
{
    int a[]={4,3,2,8,6};
    xier_sort(a,5);
    sort_print(a,5);
    return 0;
}
