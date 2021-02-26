#include "bits/stdc++.h"
#include "stack"
using namespace std;

stack<int> st;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    while (n--)
    {
        cin>>m;
        int top=1;
        int *a=new int[m+1];
        int *b=new int[m+1];
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        for(int i=1;i<=m;i++){
            st.push(a[i]);
            while (st.top()==b[top])
            {
                st.pop();
                top++;
                if(st.empty()) break;
            }
        }
        if(st.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        while(!st.empty()) st.pop();
    }
    

    return 0;
}
