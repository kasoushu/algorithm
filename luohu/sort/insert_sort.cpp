#include "stdio.h"
#include "iostream"

using namespace std;

void sort_print(int  a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

void insert_sort(int a[],int n){
    
    for(int i=1;i<n;i++){
        int now=a[i],j;
        for(j=i-1;i>=0&&a[j]>now;j--) a[j+1]=a[j];
        a[j+1]=now;
    }

}

int main(int argc, char const *argv[])
{   
    int a[]={1,3,2,7,5};
    insert_sort(a,5);
    sort_print(a,5);
    return 0;
}
