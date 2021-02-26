#include "string"
#include "iostream"
#include "bits/stdc++.h"
using namespace std;
/*
in         ABEDFCHG
pre        CBADEFGH
subsequent AEFDBHGC
*/
void tran(string preorder,string inorder){
    if(preorder.size()==0) return;
    char root=preorder[0];
    int k=inorder.find(root);
    // cout<<root;
    string prel=preorder.substr(1,k);
    string prer=preorder.substr(k+1);
    string inl=inorder.substr(0,k);
    string inr=inorder.substr(k+1);
    // cout<<"test"<<prel<<' '<<inl<<' '<<prer<<' '<<inr<<endl; 
    tran(prel,inl);
    tran(prer,inr);
    cout<<root;
    return;
}


int main(int argc, char const *argv[])
{
    string  pre,in;
    cin>>in;
    cin>>pre;
    // cout<<in<<pre;
    tran(pre,in);
    return 0;
}
