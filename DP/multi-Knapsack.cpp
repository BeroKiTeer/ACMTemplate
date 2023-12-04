#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e5+5;
int n,C,dp[MAXN],q[MAXN],num[MAXN];
//状态转移方程：dp[b + y*c[i]] = max(dp[b + x*c[i]] - x * v[i] + y*w[i])
int main ()
{
	cin >> n >> C;
	memset(dp,0,sizeof(dp));
	for (int i = 1 ; i <= n ; ++i ) {
		int w,c,m;
		cin >> w >> c >> m;
		if (m > C/c) {
			m = C/c;
		}
		for (int b = 0 ; b < c ; ++b ) {
			int head = 1,tail = 1;
			for (int y = 0 ; y <= (C-b)/c ; ++y ) {
				int tmp = dp[b + y*c] - y*w;
				while (head < tail && q[tail - 1] <= tmp) {
					tail--;
				}
				q[tail] = tmp;
				num[tail++] = y;
				while(head < tail && y - num[head] > m) { 
					head++;
				}
				dp[b + y*c] = max(dp[b + y*c] , q[head] + y*w);
			}
		}
	}
	cout << dp[C] << endl;
	return 0;
}