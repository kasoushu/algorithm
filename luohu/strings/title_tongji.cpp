#include "string"
#include "stdio.h"
#include "iostream"
int main(){
    char  s[20];
    int count=0;
    std::cin.getline(s,20);
    for (int i = 0; i <=4 ; ++i) {
        if ((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) count++;
    }
    printf("%d",count);
    return 0;
}