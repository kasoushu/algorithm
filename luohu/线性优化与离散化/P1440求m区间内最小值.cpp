#include <iostream> 
#include <algorithm> 
#include <vector>
#include "deque"
using  namespace std;
 
struct node
{
    /* data */
    int val,pos;
}a[200005];

deque<node> dq;
int ans[200005]={0};
int n,m;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].val);
        a[i].pos=i;
    }
    ans[0]=0;
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.back().val>a[i].val) dq.pop_back();
        dq.push_back(a[i]);
        while(dq.front().pos<=i-m) dq.pop_front();
        ans[i]=dq.front().val;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}