#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int q(int n,int m,int cur){
    if(cur>n) return 0;
    if(cur<=m) return 1+q(n,m,cur*2);
    if(cur>m) return 1+q(n,m,cur+m);
    return 0;
}

int main(){
    cout<<q(20,3,1);
    cout<<q(100,5,1);
    return 0;
}