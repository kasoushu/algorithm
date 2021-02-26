#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s1,s2;
        cin>>s1>>s2;
    int len2=s2.size();
    int ans=0;
    for(int i=0;i<s1.size();i++){
        for(int j=len2-1;j>=1;j--){
            if(s1[i]==s2[j]&&s1[i+1]==s2[j-1]) ans++;
        }
    }
    cout<<(1<<ans);
    return 0;
}
