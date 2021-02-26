#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

const int mm = 1005;

int main(int argc, char *argv[])
{
    string a,b;
    while(1){
        cin>>a;
        if(a=="#") break;
        cin>>b;
        cout<<a<<' '<<b<<endl;
        int pi[1005]={0};
        for(int i=1;i<b.size();i++){
            int j=pi[i-1];
            while(j&&b[j]!=b[i]) j=pi[j-1];
            if(b[j]==b[i]) j++;
            pi[i]=j;
        }
        int j=0,cnt=0;
        for(int i=0;i<a.size();i++){
            while(j&&a[i]!=b[j]) j=pi[j-1];
            if(a[i]==b[j]) j++;
            if(j==b.size()){
                cnt++;
                j=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
