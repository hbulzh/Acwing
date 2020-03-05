#include <bits/stdc++.h> 
using namespace std;

const int N = 1e5+10,M = N, INF = 0x3f3f3f3f;
int n;
int to[M],nxt[M],w[M],h[N],tot;
int d1[N],d2[N],up[N],p1[N],p2[N];
void add(int from,int t,int c)
{
	to[tot] = t, nxt[tot] = h[from], w[tot] = c;
	h[from] = tot++;
}

int dfs_d(int u,int fa)
{
	d1[u] = d2[u] = -INF;
	for(int i = h[u]; ~i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		int d = dfs_d(to[i],u) + w[i];
		if(d >= d1[u])
		{
			d2[u] = d1[u]; d1[u] = d;
			p2[u] = p1[u]; p1[u] = to[i];
		}
		else if(d > d2[u]) d2[u] = d, p2[u] = to[i];
	}
	if(d1[u] == -INF) d1[u] = d2[u] = 0;
	return d1[u];
}
void dfs_u(int u,int fa)
{
	for(int i = h[u]; ~i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		if(p1[u] == to[i]) up[to[i]] = max(up[u],d2[u]) + w[i];
		else up[to[i]] = max(up[u],d1[u] + w[i]);
		
		dfs_u(to[i],u);
	}
}
int main()
{
	memset(h, -1, sizeof h); tot = 0;
	cin >> n;
	for(int i = 0; i < n - 1; ++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c); add(b,a,c);	
	} 
	dfs_d(1,-1);
	dfs_u(1,-1);
	int res = INF;
	for(int i = 1; i <= n; ++i) res = min(res,max(up[i],d1[i]));
	cout << res;
}
