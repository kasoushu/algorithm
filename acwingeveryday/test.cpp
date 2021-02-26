#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> origin/master
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
#define PII pair<int,int> 
using namespace std;

<<<<<<< HEAD

int main(int argc, char *argv[])
{
    queue<int> q;
    q.push(5);
    q.pop();

=======
const int mm = 100;
char c[mm];
int main(int argc, char *argv[])
{
    int n ;
    vector<int> a;
    for(int i =1;i<=n;i++){
        // scanf("%c",&c[i]);
        // cin>>c[i];
        a.push_back(i);
    }
    a.clear();
    cout<<a.size();
>>>>>>> origin/master
    return 0;
}
