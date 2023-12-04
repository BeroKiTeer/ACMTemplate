#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 1e5+5;
char s[MAXN];
int trie[MAXN][65],cnt[MAXN],idx;
int getnum(char x)			//映射字符
{
	if(x >= 'A' && x <= 'Z')  return x - 'A';				//大写字母
	else if(x >= 'a' && x <= 'z') return x - 'a' + 26;		//小写字母
	else return x - '0' + 52;								//数字
} 
void insert(char str[])
{
	int p = 0 , len = strlen(str);
	for(int i = 0 ; i < len ; i++ ) {
		int c = getnum(str[i]);
		if(!trie[p][c]) {
			trie[p][c] = ++idx;
		}
		p = trie[p][c];
	}
	cnt[p]++;
}
int find(char str[])
{
	int p = 0,len = strlen(str);
	for(int i = 0 ; i < len ; i++){
		int c = getnum(str[i]);
		if(!trie[p][c]) {
			return 0;
		}
		p = trie[p][c];
	}
	return cnt[p];
}
int main ()
{
	string str;
	for (int i = 0 ; i < 10 ; i++ ) {
		cin >> s; 
		insert(s);
		cout  << s << endl;
	}
	cout << "--------------\n";
	for (int i = 0 ; i < 5 ; i++ ) {
		cin >> s;
		cout << "次数：" << find(s) << endl;
	}
	return 0;
}