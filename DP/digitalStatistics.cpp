#include <iostream>
using namespace std;
#define int long long
const int MAXN = 20;
int ten[MAXN], dp[MAXN], cnta[MAXN], cntb[MAXN],num[MAXN];
void init() 
{
	ten[0] = 1;						//10的i次方
	for (int i = 1 ; i < MAXN ; ++i ) {
		dp[i] = i*ten[i-1];			//或者写成dp[i] = dp[i-1]*10+ten[i-1];
		ten[i] = 10*ten[i-1];
	}
}
//数位统计dp
void digitalStatistics(int x,int *cnt)
{
	int len = 0;				//数字有多少位
	while (x) {					//分解x。num[i]为第i位数字
		num[++len] = x%10;
		x /= 10;
	}
	for (int i = len ; i >= 1 ; --i ) {		//从高位到低位处理x的每一位
		for (int j = 0 ; j <= 9 ; ++j ) {	
			cnt[j] += dp[i-1]*num[i];
		}
		for (int j = 0 ; j < num[i] ; ++j ) {	//特判最高位比num[i]小的数字
			cnt[j] += ten[i-1];
		}
		int num2 = 0;
		for (int j = i - 1 ; j >= 1 ; --j) {	
			num2 = num2*10 + num[j];
		}
		cnt[num[i]] += num2 + 1;		//特判最高位数字num[i]
		cnt[0] -= ten[i-1];				//减去前导0
	}
}
void query(int a,int b)
{
	digitalStatistics(a-1,cnta);
	digitalStatistics(b,cntb);
}
signed main () 
{
	init();
	int a,b;cin >> a >> b;
	query(a,b);
	for (int i = 0 ; i < 10 ; ++i ) {
		cout << cntb[i] - cnta[i] << " ";
	}
	return 0;
}