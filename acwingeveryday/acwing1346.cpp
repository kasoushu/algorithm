#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string trans(int i,int b){
    string ans="";
    while(i){
        int c=i%b;
        if(c<=9){
            ans+=(char)(c)+'0';

        }else if(c>=10){
            ans+=(char)(c)+'A';
        }
        i/=b;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

bool check(string s2){
    string s=s2;
    reverse(s.begin(),s.end());
    int l=s.size();
    for(int i=0;i<l/2;i++) if(s[i]!=s2[i]) return false;
    return true;
}



int main(int argc, char const *argv[])
{
    int b;
    cin>>b;
    for(int i=1;i<=300;i++){
        string k=trans(i*i,b);
        if(check(k)){
            printf("%d %d\n",i,i*i);
        }
    }
    return 0;
}
