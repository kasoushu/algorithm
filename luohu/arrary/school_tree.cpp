#include "stdio.h"

int main(){
    int m,l,ans=0;
    int a[10001]={0};
    scanf("%d%d",&l,&m);
    for (int i = 1; i <=m ; ++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        for (int j = u; j <=v ; ++j) {
            a[j]++;
        }
    }
    for (int i = 0; i <=l ; ++i) {
        if (a[i]==0)
            ans++;
    }
    printf("%d",ans);
    return 0;
}