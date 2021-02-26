#include "iostream"
#include "string"

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
    string prel=preorder(1,k);
    string prer=preorder(k+1);
    string inl=inorder(0,k-1);
    string inr=inorder(k+1);

    tran(prel,inl);
    tran(prer,inr);
    cout<<root;
}

int main(int argc, char const *argv[])
{
    
    string s="hello";
    cout<<s.substr(0);
    return 0;
}
