#include "iostream"
#include "vector"
#include "queue"
using namespace std;
int grid[20][20]={0},n;
int hang[20]={0};
int lie[20]={0};
int xie1[20]={0}; // / 这么斜 i+j
int xie2[20]={0}; // \ 这么斜 i-j+n
vector< vector <int> > ans;
vector<int > now;
int sum=0;

void dfs(int p){
    if(p>=n) {sum++;ans.push_back(now);}

        for(int j=0;j<n;j++){
            if(lie[j]==0&&xie1[p+j]==0&&xie2[p-j+n]==0){
                // cout<<hang[i]<<lie[j]<<xie1[i+j]<<xie2[i-j+n];
                now.push_back(j);
                lie[j]=1;
                xie1[p+j]=1;
                xie2[p-j+n]=1;
                dfs(p+1);
                lie[j]=0;
                xie1[p+j]=0;
                xie2[p-j+n]=0;
                now.pop_back();
            }
        }
    

}
void print_grid(int k){
    k>=3?k=3:k;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++) cout<<ans[i][j]+1<<' ';
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    dfs(0);
    print_grid(sum);
    cout<<sum;
    return 0;
}
