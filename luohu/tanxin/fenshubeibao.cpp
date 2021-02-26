//vector// vec
#include "iostream"
#include "algorithm"
// #include "vector"
using namespace std;
int n,l,i=0;
typedef struct skda{
    int w;
    int v;
}node;


node a[105];
// // vector<vector<int> > a;
// bool cmp(vector<int> a,vector<int> b){
//     return (a[1]*1.0/a[0])>(b[1]/b[0])?1:0;
// }
bool cmp(node a,node b){
    return a.v*1.0/a.w>b.v*1.0/b.w?1:0;
}


double result(int load){
    double sum=0;
    if (a[i].w>load){
        return load*1.0*a[i].v/a[i].w;
    }else
    {
        sum+=a[i].v;
        load-=a[i].w;
        i++;
        sum+=result(load);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    cin>>n>>l;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        // vector<int > p(2);
        a[i].w=x,a[i].v=y;
        // p[0]=x,p[1]=y;
        // a.push_back(p);
    }
    sort(a,a+n,cmp);
    // for(int i=0;i<n;i++) cout<<a[i][0]<<' '<<a[i][1]<<endl;
    // cout<<result(l);
    printf("%.2f",result(l));
    return 0;
}
