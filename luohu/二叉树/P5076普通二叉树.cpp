/*
 * @Author: @Katwo 
 * @Date: 2020-11-21 22:52:21 
 * @Last Modified by: @Katwo
 * @Last Modified time: 2020-11-21 23:15:35
 */

#include "iostream"
#include "bits/stdc++.h"
//普通二叉树
const int INF=0x7fffffff;
using namespace std;

struct node
{
    int val,l,r,size,cnt;
    /* data */
}tree[500005];

int ct,n,opt,xx;

inline void add(int root,int v){
    tree[root].size++;
    if(tree[root].val==v){
        tree[root].cnt++;
        return;
    }
    if(tree[root].val>v){
        if(tree[root].l!=0){
            add(tree[root].l,v);
        }else
        {
            ct++;
            tree[ct].val=v;
            tree[ct].size=tree[ct].cnt=1;
            tree[root].l=ct;
        }
    }else
    {
        if(tree[root].r!=0){
            add(tree[root].r,v);
        }else
        {
            ct++;
            tree[ct].val=v;
            tree[ct].cnt=tree[ct].size=1;
            tree[root].r=ct;
        }
    }
}

int queryfr(int root,int v,int ans){
    if(tree[root].val>=v){
        if(tree[root].l==0) return ans;
        else{
            return queryfr(tree[root].l,v,ans);
        }
    }else
    {
        if(tree[root].r==0) return tree[root].val;
        return queryfr(tree[root].r,v,tree[root].val);
    }
    
}

int querysub(int root,int v,int ans){
    if(tree[root].val<=v){
        if(tree[root].r==0) return ans;
        else return querysub(tree[root].r,v,ans);
    }else{
        if(tree[root].l==0) return tree[root].val;
        return querysub(tree[root].l,v,tree[root].val);
    }
}

int queryrk(int root,int rk){
    if(root==0) return INF;
    if(tree[tree[root].l].size>=rk) return queryrk(tree[root].l,rk);
    if(tree[tree[root].l].size+tree[root].cnt>=rk) return tree[root].val;
    return queryrk(tree[root].r,rk-tree[tree[root].l].size-tree[root].cnt);    
}

int queryval(int root,int val){
    if(root==0) return 0;
    if(val==tree[root].val) return tree[tree[root].l].size;
    if(val<tree[root].val) return queryval(tree[root].l,val);
    return queryval(tree[root].r,val)+tree[tree[root].l].size+tree[root].cnt;
}

int main(int argc, char const *argv[])
{
    cin>>n;
    while(n--){
        cin>>opt>>xx;
        if(opt==1) printf("%d\n",queryval(1,xx)+1);
        else if(opt==2) printf("%d\n",queryrk(1,xx));
        else if(opt==3) printf("%d\n",queryfr(1,xx,-INF));
        else if(opt==4) printf("%d\n",querysub(1,xx,INF));
        else{
            if(ct==0){
                ct++;
                tree[ct].cnt=tree[ct].size=1;
                tree[ct].val=xx;
            }else{
                add(1,xx);
            }
        }
    }
    return 0;
}
