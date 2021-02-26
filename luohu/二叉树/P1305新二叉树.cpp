/*
 * @Author: @Katwo 
 * @Date: 2020-11-22 23:14:06 
 * @Last Modified by:   @Katwo 
 * @Last Modified time: 2020-11-22 23:14:06 
 */
#include "iostream"
#include "map"
#include "bits/stdc++.h"
using namespace std;
struct node
{
    int l,r;
    /* data */
}a[28];

void pre_order(int root){
    if(root==27) return;
    printf("%c",root+'a');
    pre_order(a[root].l);
    pre_order(a[root].r);
}

int main(int argc, char const *argv[])
{
    int n;
    string s;
    char begin;
    cin>>n;
    int q=n;
    while(n--){
        cin>>s;
        if(n==q-1) begin=s[0];
        a[s[0]-'a'].l=(s[1]=='*'?27:s[1]-'a');
        a[s[0]-'a'].r=(s[2]=='*'?27:s[2]-'a');
    }
    pre_order(begin-'a');
    return 0;
}
