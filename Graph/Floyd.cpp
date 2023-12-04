#include <iostream>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 405;
int dp[MAXN][MAXN];
int n,m,q;
void floyd()
{
    for (int k = 0 ; k < n ; ++k) {
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j ) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}
signed main ()
{
    return 0;
}