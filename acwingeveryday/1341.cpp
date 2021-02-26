#include "vector"
#include "bits/stdc++.h"
#include "map"
#include "queue"
#include "algorithm"
#include "stdio.h"
#include "iostream"
#define ll long long
#define INF 0x3f3f3f3f
#define low_bit(x) ((x)&(-x))
using namespace std;
int week(int y, int m, int d)
{
    if (m == 1 || m == 2)
        m = m + 12, y--;
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;//公式
}
int main()
{
    int n = 0;
    cin >> n;
    int weekday[7] = {0};//存储星期的天数
    for (int y = 1900; y < 1900 + n; y++)
        for (int m = 1; m <= 12; m++)
        {
            int w = week(y, m, 13);//公式计算每一年，每一月的13号是星期几
            weekday[w]++;//对应星期天数加 1
        }

    for(int i = 6; i < 6 + 7; i++)
        cout << weekday[i % 7] << " ";
    return 0;
}
