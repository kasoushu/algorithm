#include "stdio.h"
#include <iostream>

using namespace std;
inter
int main(){
    char b;
    for (scanf("%c",&b); b !='\n' ; scanf("%c",&b)){
        if (b>='a'&&b<='z'){b-=32;}
        printf("%c",b);
    }
    return 0;
}