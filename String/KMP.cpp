#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAXN = 2e5+5;
char str[MAXN],patten[MAXN];
int Next[MAXN],cnt;
//计算next数组
void getNext(char *p,int plen) 
{
	Next[0]=0;Next[1]=0;
	for (int i = 1 ; i < plen ; ++i ) {
		int j = Next[i];
		while(j && p[i] != p[j]) { 
			j = Next[j];
		}
		if (p[i] == p[j]) {
			Next[i+1] = j + 1;
		} else {
			Next[i+1] = 0;
		}
	}
}
void kmp (char *s,char *p)
{
	int last = -1;
	int slen = strlen(s),plen = strlen(p);
	getNext(p,plen);
	int j = 0;
	for (int i = 0 ; i <slen ; ++i ) {
		while (j && s[i] != p[i]) {
			j = Next[j];
		}
		if (s[i] == p[i]) j++;
		if (j == plen) {
			if (i - last >= plen) {
				cnt++;
				last = i;
			}
		}
	}
}
int main ()
{
	int t;cin >> t;
	while (t--) {
		memset(str,0,sizeof(str));
		memset(patten,0,sizeof(patten));
		memset(Next,0,sizeof(Next));
		int n,k;cin >> n >> k;
		cnt = 0;
		scanf("%s",str);
		for (int i = 0 ; i < k ; ++i ) {
			patten[i] = 'W';
		}
		kmp(str,patten);
		cout << cnt << endl;
	}
	return 0;
}