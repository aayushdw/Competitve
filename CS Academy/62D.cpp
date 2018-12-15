#include <bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

const int MAXN = 1005;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

bool IS_BRIDGE(int u,int v)
{
	return (fup[u] > tin[v]) || (fup[v] > tin[u]);
}

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            // if (fup[to] > tin[v])
            //     IS_BRIDGE(v,to);
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; ++i)
        used[i] = false;
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs (i);
}

bitset<MAXN> vis;
vector<int> path;

bool DFS(int u,int v)
{
	vis[u] = true;
	if(v==u)
	{
		path.pb(u);
		return true;
	}
	rep(i,0,g[u].size())
	if(!vis[g[u][i]])
	{
		bool x = DFS(g[u][i],v);
		if(x)
		{
			path.pb(u);
			return true;
		}
	}
	return false;
}

bool existsSimplePath(int u,int v)
{
	path.clear();
	vis.reset();
	if(DFS(u,v))
		rep(i,1,path.size())
			if(!IS_BRIDGE(path[i],path[i-1]))
				return false;
	return true;
}

int main()
{
	int n,m,q;
	si(n); si(m); si(q);
	while(m--)
	{
		int u,v;
		si(u); si(v);
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	find_bridges(n);
	while(q--)
	{
		int u,v;
		si(u); si(v);
		u--; v--;
		if(existsSimplePath(u,v))
			pr(1);
		else
			pr(0);
	}
	return 0;
}