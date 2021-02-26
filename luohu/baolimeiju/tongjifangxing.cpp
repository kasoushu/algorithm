#include "stdio.h"
#include "algorithm"
#include "iostream"
#include "stdlib.h"
#include <stdio.h>
#include "algorithm"


using namespace std;

int main(int argc, char const *argv[]){
	long long n,m;
	long long count_zheng=0,chang;
	cin>>n>>m;
	 chang=((n+1)*n/2)*((m+1)*m/2);
	for (int  a = 1; a <=min(n,m) ; ++a)
	{
	    count_zheng+=(n-a+1)*(m-a+1);
	}
	cout<<count_zheng<<' '<<chang-count_zheng;
}
//long long M,N,x,y;
//long long min(int a, int b) {
//    return a<b?a:b;
//}
//int main() {
//    scanf("%lld%lld",&M,&N);
//    x=((M+1)*M/2)*((N+1)*N/2);
//    for(long long i=1; i<= min(M,N); i++) {
//        y+=(M-i+1)*(N-i+1);
//    }
//    printf("%lld %lld", y, x-y);
//    return 0;
//}