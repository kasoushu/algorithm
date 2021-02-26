#include "stdio.h"
#include "vector"
#include "iostream"
#include "array"
int main(){
   std::vector<int> a(3);
   std::vector<int> b(a);
   std::vector<int>::iterator it= a.begin();
   for(int i=0;i<4;i++) a[i]=5;
   for (;it!=a.end();it++) {

      std::cout<<*it;
   }

    // std::array<int,5> v1{1,2,3,4,5};
    // std::array<int,5> v2;
    // std::array<int,5> v3{1,2,3,4,5};
    // v2.fill(0);
    // for(int i :v1){
    //     std::cout<<i;
    // }

    // for(int i :v2){
    //     std::cout<<i;
    // }
    // std::cout<<v2.operator[](3)<<std::endl;
    // std::cout<<v2.size()<<(v3==v1);
    // return 0;
}