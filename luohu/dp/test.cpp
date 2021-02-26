#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#include <utility>
using namespace std;
typedef pair<int, int> pii;
pii lss;
int main(int argc, char *argv[])
{
  int a[5]={2,3,5,6,9};
  *upper_bound(a,a+5,3) = 4;

  for(int i=0;i<5;i++) cout<<a[i]<<' ';
  return 0;
}
