#include "bits/stdc++.h"
using namespace std;



int main(int argc, char const *argv[])
{
    char c;int a=0;
    stack<int> v;
    int x,y;
    cin>>c;
    while (c!='@')
    {
        if(c=='.'){v.push(a);a=0;}
        else if(c<='9'&&c>='0'){a=a*10+c-'0';}
        else {
            if(c=='+'){x=v.top();v.pop();y=v.top();v.pop();v.push(x+y);}
            if(c=='-'){x=v.top();v.pop();y=v.top();v.pop();v.push(y-x);}
            if(c=='*'){x=v.top();v.pop();y=v.top();v.pop();v.push(x*y);}
            if(c=='/'){x=v.top();v.pop();y=v.top();v.pop();v.push(y/x);}
        }
        cin>>c;
    }
    cout<<v.top();
    return 0;
}
