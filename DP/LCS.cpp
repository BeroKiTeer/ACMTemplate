#include <iostream>
#include <cstring>
using namespace std;
char a[200]="ADABBC";
char b[200]="DBDCA";
char dp[201][201];//长度数组
char p[201][201];//前驱数组
int m,n;
void LCS()	//最长长度
{
	m = strlen(a);
	n = strlen(b);
	for (int i = 1 ; i <= m ; i++ ) {
		for (int j = 1 ; j <= n ; j++ ) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				p[i][j] = 1;
			} else if (dp[i][j-1] > dp[i-1][j]) {
				dp[i][j] = dp[i][j-1];
				p[i][j] = 2;
			} else {
				dp[i][j] = dp[i-1][j];
				p[i][j] = 3;
			}
		}
	}
	printf("%d\n",dp[m][n]);
}
void getLCS()	//倒推公共子序列
{
	int i = m , j = n , k = dp[m][n];
	char s[200];
	while(i>0&&j>0){
		if (p[i][j] == 1) {
			s[k--] = a[i-1];
			i--;j--;
		} else if (p[i][j] == 2) {
			j--;
		} else {
			i--;
		}
	}
	for (int i = 1 ; i <= dp[m][n] ; i++ ) {
		printf("%c",s[i]);
	}
	printf("\n");
}
int main ()
{
	LCS();
	getLCS();
	return 0;
}