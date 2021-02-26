#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){return a<b;}
int main(int argc, char const *argv[])
{
    
    string s="hhhlba";
    // vector<int> s={1,4,4,3};
    for(int i=0;i<4;i++){
    auto k=min_element(s.begin(),s.end(),cmp);
    cout<<*k;
    s=s.substr(0,s.size()-1);
    }
    cout<<"hello world";
    return 0;
}
