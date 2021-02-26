/*
 * @Author: @Katwo 
 * @Date: 2020-11-22 23:14:01 
 * @Last Modified by: @Katwo
 * @Last Modified time: 2020-11-22 23:34:02
 */
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string get_sub_order(string a,string b){// a,zhongxu,b, houxu
    string ans="";
    if(a.size()>0&&b.size()>0){
        char root=b[b.size()-1];
        int k=a.find(root);
        printf("%c",root);
        ans+=get_sub_order(a.substr(0,k),b.substr(0,k));
        ans+=get_sub_order(a.substr(k+1),b.substr(k,b.size()-1-k));
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    string s1,s2;//s1 中序,s2 后序
    cin>>s1>>s2;
    // get_sub_order(s1,s2);
    cout<<get_sub_order(s1,s2);
    return 0;
}
