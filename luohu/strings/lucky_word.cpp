#include "stdio.h"
#include "string.h"

int main(){
    char s[110];
    int count[26]={0};
    int max=0,min=110,n;
    scanf("%s",s);
    n=strlen(s);
    for (int i = 0; i <n ; ++i) {
        count[s[i]-'a']++;
    }
    for (int i = 0; i <26 ; ++i) {
        if (count[i]>max) max=count[i];
        if (count[i]<min&&count[i]>=1) min=count[i];
    }
    if (((max-min)%2!=0&&(max-min)%3!=0&&(max-min)%5!=0&&(max-min)%7!=0)||(max-min)==2||(max-min)==3||(max-min)==5||(max-min)==7) printf("Lucky Word\n%d",max-min);
    else  printf("No Answer\n0");
    return 0;
}