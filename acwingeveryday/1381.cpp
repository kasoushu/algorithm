#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
<<<<<<< HEAD
#define ui unsigned int
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))

typedef std::pair<int,int> pii;
using namespace std;

int n,m;
int a[10005];
ll b[10005]={0};
int main(int argc, char *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    b[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=m;j++){
            b[j]+=b[j-a[i]];
        }
    }
    cout<<b[m];
=======
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;

int main(int argc, char *argv[])
{
    int n,tot1=0,tot2=0;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(!(temp%2)){tot1++;temp/=2;}
        while(!(temp%5)){tot2++;temp/=5;}
        ans=ans*temp%10;
    }
    for(int i=0;i<tot1-tot2;i++) ans=ans*2%10;
    cout<<ans<<endl;
>>>>>>> origin/master
    return 0;
}
