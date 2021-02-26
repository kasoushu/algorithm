#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <unordered_map>
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;


queue<int> q;
unordered_map<int, int> g;
int cnt=0;
int m,n;

int main(int argc, char *argv[])
{
    cin>>m>>n;
    int x;
    while(cin>>x){
        if(g.find(x)==g.end()){
            if(g.size()==m){
                g.erase(q.front());
                q.pop();
            }
                q.push(x);
                g[x]=x;
                cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
