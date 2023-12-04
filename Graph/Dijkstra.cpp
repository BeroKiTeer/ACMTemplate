#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6+7;
struct edge {
	int to,v;
};
bool operator<(const edge &one , const edge &other) {
	return one.v > other.v;
}
int n,m,start;
vector<edge>v[MAXN];
int dis[MAXN],vis[MAXN];
priority_queue<edge>pq;
//堆优化dijkstra
void dijkstra (int s) 
{
	memset(dis,INF,sizeof(dis));
	dis[s] = 0;
	pq.push({s,233});
	while(!pq.empty()){
		int now = pq.top().to;
		pq.pop();
		vis[now] = true;
		for (auto nxt : v[now]) {
			int nx = nxt.to;
			dis[nx] = min(dis[nx],dis[now]+nxt.v);
			if (!vis[nx]) {
				pq.push({nx,dis[nx]});
			}
		}
	}
}
int main ()
{
	scanf("%d%d%d",&n,&m,&start);
	for (int i = 1 ; i <= m ; i++ ) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back({y,z});
	}
	dijkstra(start);
	for (int i = 1 ; i < n ; i++ ){
		printf("%d ",dis[i]);
	}
	printf("%d\n",dis[n]);
	return 0;
}