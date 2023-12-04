#include <iostream>
using namespace std;
const int N = 1e7;
int prime[N+1];
bool vis[N+1];
int E_sieve(int n) 
{
    int k = 0;
    for (int i = 0 ; i <= n ; ++i ) {
        vis[i] = false;
    }
    for (int i = 2 ; i <= n ; ++i ) {
        if (!vis[i]) {
            prime[k++] = i;
            for (int j = 2*i ; j <= n ; j += i) {
                vis[j] = true;
            }
        }
    }
    return k;
}
int main ()
{
    return  0;;
}