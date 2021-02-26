#include "stdio.h"
#include "iostream"
#include "array"
#include "vector"

using namespace std;

void merge (int a[],int p,int q,int r){
  vector<int> c(q-p+1),d(r-q);
  for (int i=0;i<q-p+1;i++) c[i]=a[p+i];
  for (int i=0;i<r-q;i++) d[i]=a[q+i+1];
  int x=0,y=0,i=0;
  // for(int i=0;i<q-p+1;i++) cout<<c[i]<<' ';
  while (x<q-p+1&&y<r-q){
    if(c[x]<d[y]) {a[p+i]=c[x];x++;i++;}
    if(c[x]>d[y]) {a[p+i]=d[y];y++;i++;}
  }
  if(i<r-p+1){
    if(x<q-p+1) while(i<r-p+1) a[p+(i++)]=c[x++];
    else while(i<r-p+1) a[p+(i++)]=d[y++];
  }
}
void merge_sort(int a[],int p,int r){
  if(p<r){
    int q=(p+r)/2;
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    merge(a,p,q,r);
  }
}
int main(int argc, char const *argv[]) {
  int a[4]={3,2,5,4};
  // for(int i=0;i<2;i++) cout<<a[i]<<' ';
  merge_sort(a,0,3);
  for(int i=0;i<4;i++) cout<<a[i]<<' ';
  return 0;
}

