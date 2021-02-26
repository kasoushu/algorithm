#include "bits/stdc++.h"
#include "stdio.h"
#include "iostream"
#include "vector"
using namespace std;

int n,h,t;
int a[100005];
double b[100005];
double s[100005]={0};
bool check(double mid){
  deque<int> qq;
  for(int i=1;i<=n;i++){
    b[i]=((double)(a[i])-mid);
  }
  for(int i=1;i<=n;i++){
    s[i]=s[i-1]+b[i];
    // cout<<s[i]<<' ';
  }
  
  for(int i=h;i<=n;i++){
    while(!qq.empty()&&s[qq.back()]>s[i-h]) qq.pop_back();
    qq.push_back(i-h);
    while(!qq.empty()&&qq.front()<i-t) qq.pop_front();
    // cout<<"check"<<s[i]<<' '<<s[qq.front()]<<' '<<s[i]-s[qq.front()]<<endl;
    if(!qq.empty()&&s[i]-s[qq.front()]>=0) return true;

  }
  return false;
}



int main(){
  //int x,y;
  //printf("%d",x);
  cin>>n>>h>>t;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  double ans=0;
  double l=-10000,r=10000;
  while(r-l>0.00001){
    double mid=(l+r)/2;
    if(check(mid)){
      // cout<<"chech mid="<<check(mid)<<endl;
      // cout<<ans<<endl;
      ans=l=mid;
    }else{
      r=mid;
    }
  }
  printf("%.3lf",ans);

}
