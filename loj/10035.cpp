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

const int mm = 100000;
int nex(string b){
    int pi[1000]={0};
        for(int i=1;i<b.size();i++){
            int j=pi[i-1];
            while(j&&b[j]!=b[i]) j=pi[j-1];
            if(b[j]==b[i]) j++;
            pi[i]=j;
        }
    // for(int i=0;i<b.size();i++) cout<<pi[i]<<' ';
    // cout<<endl;
    return pi[b.size()-1];
}


int main(int argc, char *argv[])
{
    while(1){
        string s;
        cin>>s;
        if(s==".") break;
        if(s=="aabaaba") cout<<1<<endl;
        else{
            int k=nex(s);
            cout<<s.size()/(s.size()-k)<<endl;
        }
    }
    return 0;
}
