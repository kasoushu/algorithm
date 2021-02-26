#include "bits/stdc++.h"
#include "queue"
#include "iostream"
#include "stdio.h"
#include <vector>

using namespace std;

priority_queue<int, vector<int>,less<int> > q1;
priority_queue<int,vector<int> ,greater<int> > q2;
int a[100008];
int n,mid;
int main(){
  cin>>n;
  scanf("%d",&a[1]);
  mid=a[1];
  printf("%d\n",mid);
  for(int i=2;i<=n;i++){
    scanf("%d",&a[i]);
    if(a[i]>mid) q2.push(a[i]);
    else q1.push(a[i]);

    if(i%2==1){
      if(q1.size()!=q2.size()){
        if(q1.size()<q2.size()){
          q1.push(mid);
          mid=q2.top();
          q2.pop();
        }else{
          q2.push(mid);
          mid=q1.top();
          q1.pop();
        }
      }
      printf("%d\n",mid);
    }
  }
}
