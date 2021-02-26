#include "string.h"
#include "stdio.h"
#include "iostream"

int main(){
    char b[10],s[100][100],a;
    int k,d,n;
    std::cin>>n;
    for (int i = 1; i <=n; ++i) {
        std::cin>>b;
        if (b[0]>='a'&&b[0]<='z') {
            a=b[0];
            std::cin>>k>>d;
        } else{
            sscanf(b,"%d",&k);
            std::cin>>d;
        }
//        char s[100];
        switch (a) {
            case 'a':sprintf(s[i],"%d+%d=%d",k,d,k+d);break;
            case 'b':sprintf(s[i],"%d-%d=%d",k,d,k-d);break;
            case 'c':sprintf(s[i],"%d*%d=%d",k,d,k*d);break;
        }
    }
    for (int i = 1; i <=n ; ++i) {
        printf("%s\n%zu",s[i],strlen(s[i]));
    }
    return 0;
}