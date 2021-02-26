#include "stdio.h"
#include "iostream"

using namespace std;

void sort_print(int  a[],int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}
void quick_sort(int a[],int left,int right){
    int i=left+1,j=right,t=a[left];
    if (left<right){
        do{
            while(a[i]<t)i++;
            while(a[j]>t)j--;
            if(i<j){
                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }while(i<j);
        int temp=a[j];
        a[j]=a[left];
        a[left]=temp;
        quick_sort(a,left,j-1);
        quick_sort(a,j+1,right);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int a[100000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    quick_sort(a,0,n-1);
    sort_print(a,n);
    return 0;
}
