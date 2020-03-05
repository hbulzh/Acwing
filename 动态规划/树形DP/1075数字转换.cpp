#include <bits/stdc++.h>

using namespace std;
const int N = 5e4+10;
int tot,h[N],sum[N],vis[N];
struct Edge{
    int to,nxt,w;
}e[N];
int ans;
void add(int from,int to,int w)
{
    e[tot].to = to, e[tot].w = w, e[tot].nxt = h[from];
    h[from] = tot ++;
}
int dfs(int u)
{
    int d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = e[i].nxt)
    {
        int to = e[i].to;
        int d = dfs(to) + 1;
        if(d >= d1) d2 = d1, d1 = d;
        else if(d > d2) d2 = d;
    }
    ans = max(ans,d1 + d2);
    //cout << d1 << ' ';
    return d1;
}
int main()
{
    memset(h, -1, sizeof h);
    int n; cin >> n;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 2; j <= n / i; ++j)
            sum[i * j] += i;
    for(int i = 2; i <= n; ++i)
        if(i > sum[i])
        {
            
            add(sum[i],i,1);
            vis[i] = 1;
        }
    
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i);
    cout << ans;
}
