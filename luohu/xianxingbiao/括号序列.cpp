#include "bits/stdc++.h"

using namespace std;
stack<int> a;
int ok[101];
string ans;
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    char c;
    int i=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'||s[i]==']'){
            if(a.size()>0){
                if((s[a.top()]=='('&&s[i]==')')||(s[a.top()]=='['&&s[i]==']')){
                    ok[a.top()]=1;
                    ok[i]=1;
                    a.pop();
                }
            }
        }else a.push(i);
    }
    for(int i=0;i<s.length();i++){
        if(ok[i]) cout<<s[i];
        else
        {
            if(s[i]=='('||s[i]==')') cout<<"()";
            else cout<<"[]";
        }
    }

    return 0;
}
