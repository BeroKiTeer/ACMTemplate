#include <iostream>
using namespace std;
const int MAXN = 1e6+5;
template<typename T>
struct SegmentTree {
	int n,w[MAXN];
	struct node {
		T l,r,sum,add;
	}tr[MAXN*4];
	T lc (T p)	//左子树指针
	{
		return p<<1;
	}
	T rc (T p)	//右子树指针
	{
		return p<<1|1;
	}
	void pushup(T p) //向上更新
	{
		tr[p].sum = tr[lc(p)].sum + tr[rc(p)].sum;
	}
	void pushdown (T p)	//向下更新
	{
		if (tr[p].add) {
			tr[lc(p)].sum += tr[p].add*(tr[lc(p)].r - tr[lc(p)].l + 1);
			tr[rc(p)].sum += tr[p].add*(tr[rc(p)].r - tr[rc(p)].l + 1);
			tr[lc(p)].add += tr[p].add;
			tr[rc(p)].add += tr[p].add;
			tr[p].add = 0;
		}
	}
	void build(T p,T l,T r)		//建树
	{
		tr[p] = {l,r,w[l],0};
		if (l == r) return;	//叶子
		T m = (l+r)>>1;		//不是叶子裂开
		build(lc(p),l,m);
		build(rc(p),m+1,r);
		pushup(p);
	}
	void update (T p,T x,T k)	//单点修改(+)
	{
		if (tr[p].l == x && tr[p].r == x) {
			tr[p].sum += k;
			return;
		}
		int m = (tr[p].l + tr[p].r) >> 1;
		if (x <= m) update(lc(p),x,k);
		if (x > m) update(rc(p),x,k);
		pushup(p);
	}
	void update (T p,T x,T y,T k)	//区间修改(+)
	{
		if (x <= tr[p].l && tr[p].r <= y) {
			tr[p].sum += (tr[p].r - tr[p].l + 1)*k;
			tr[p].add += k;
			return;
		}
		T m = (tr[p].l + tr[p].r)>> 1;
		pushdown(p);
		if (x <= m) update(lc(p),x,y,k);
		if (y > m) update(rc(p),x,y,k);
		pushup(p);
	}
	T query (T p,T x,T y) 		//区间查询
	{
		if (x <= tr[p].l && tr[p].r <= y) return tr[p].sum;//完全覆盖
		T m = (tr[p].l + tr[p].r) >> 1;
		pushdown(p);
		T sum = 0;
		if (x <= m) sum += query(lc(p),x,y);
		if (y > m)  sum += query(rc(p),x,y);
		return sum;
	}
};

int main ()
{
	
	return 0;
}