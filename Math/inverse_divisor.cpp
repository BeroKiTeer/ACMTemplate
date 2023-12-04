#include <iostream>
void extend_gcd(int a,int b,int& x,int& y)
{
	if(b==0){
		x=1;
		y=0;
		return;
	}
	extend_gcd(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp-(a/b)*y;
}
//除法/分数取模
int mod_inverse(int a,int m){
	int x,y;
	extend_gcd(a,m,x,y);
	return (x%m+m)%m;
}
int main ()
{
    return 0;
}