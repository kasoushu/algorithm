#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
     queue<int> a;
    map<int,int> b;
    int m,n;
    int p,cnt;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        if(b.find(p)==b.end()){
            if(b.size()<=m-1){
                a.push(p);b[p]=p;
            }
            else
            {
                int now=a.front();
                b.erase(now);
                a.pop();
                cnt++;
                a.push(p);
                b[p]=p;
            }
        }
    }
    cout<<cnt+m;
    return 0;
    
    return 0;
}
