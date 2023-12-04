#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e7;
int prime[N+1];
bool vis[N+1];
int euler_seive(int n)                              //欧拉筛。返回素数个数
{                                                   //
    int cnt = 0;                                    //记录素数个数
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));
    for (int i = 2 ; i <= n ; ++i) {                //检查每个数。筛去其中的合数
        if (!vis[i])    prime[cnt++] = i;           //如果没有筛过。是素数。记录；第一个素数为2
        for (int j = 0 ; j < cnt ; ++j ) {          //用已经得到的素数去筛后面的数
            if (i*prime[j] > n) break;              //只筛小于等于n的数
            vis[i*prime[j]] = 1;                    //关键1：用x的最小质因数筛去x
            if (i % prime[j]==0) break;             //关键2：如果不是这个数的最小质因数。则结束
        }
    }
    return cnt;
}
int main ()
{
    return 0;
}