#include <iostream>
#include <string>
#include "map"
#include "vector"
#include "bits/stdc++.h"
//命名空间
using namespace std;
int main(){
    //定义两个字符串
    vector<vector<int>> now;
    now.push_back(vector<int>{1,2,3});
    for(int i=0;i<3;i++){
        cout<<now[0][i];
    }
    string s="aaabc";
    cout<<(s.find("dd")==string::npos);
    return 0;
}