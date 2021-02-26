#include "iostream"
#include "algorithm"
#include "vector"
#include "stdio.h"
using namespace std;
double a,b,c,d;
double x,y,z;

double sanyua(double mid){
    return a*mid*mid*mid+b*mid*mid+c*mid+d;
}

bool find_x(double left,double right,double *ans){
    
    while(right-left>=0.00001){
        double mid=(left+right)/2;
        if(sanyua(mid)<=0.01&&sanyua(mid)>=-0.01) { *ans=mid; return true;}
        if(sanyua(mid)*sanyua(left)<0) right=mid-0.0001;
        else if(sanyua(mid)*sanyua(right)<0) left=mid+0.0001;
        else {left+=0.001;right-=0.001;}
    }
    double mid=(right+left)/2;
    return false;
}
bool cmp(double a,double b){
    return a-b>=0.001?0:1;
}
int main(int argc, char const *argv[])
{
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    //ax^3+bx^2+c^x1+d==0;
    double left=-100,right=100;
    vector<double> ans;
    if(find_x(left,right,&x)) ans.push_back(x);
    if(find_x(x+1,100,&y)) {
        ans.push_back(y);
        if(find_x(x+1,y-1,&z)) ans.push_back(z);
        else if (find_x(y+1,100,&z)){
            ans.push_back(z);
        }
    }else if(find_x(-100,x-1,&y)){
            ans.push_back(y);
            if(find_x(-100,y-1,&z)) ans.push_back(z);
            else if(find_x(y+1,x-1,&z)) ans.push_back(z);
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<3;i++) printf("%.2f ",ans[i]+0.001);
    // return 0;

}
