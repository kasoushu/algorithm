#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"

using namespace std;

const int mm = 1000000;

int heap[mm]={0};
int n,cnt=0;
void up (int x){
  while(x>1&&heap[x]>heap[x/2]){
    swap(heap[x],heap[x/2]);
    x/=2;
  }
}

void down(int x){
  while(x*2<=n)
  {
    int  t=x*2;
    if(t+1<=n&&heap[t+1]>heap[t]) t++;
    if(heap[t]<=heap[x]) break;
    //cout<<"down = "<<heap[t]<<' '<<heap[x]<<endl;
    swap(heap[x],heap[t]);
    x=t;
  }
}
// 向上调整建树复杂度为 theta (nlogn)
void build_heap(){
  for(int i=1;i<=n;i++) up(i);
}
// 向下调整构造复杂度为n
void build_h(){
  for(int i=n;i>=1;i--) down(i);
}

void ins(int val)
{
  n++;
  heap[n]=val;
  up(n);
}

void dele(){
  swap(heap[1],heap[cnt]);
  down(1);
  n--;
}
int main(int argc, char *argv[])
{
  int k[5]={7,8,3,5,1};
  for(int i=0;i<5;i++){
    ins(k[i]);
  }
  cout<<heap[1];
  dele();
  cout<<heap[1];
  return 0;
}
