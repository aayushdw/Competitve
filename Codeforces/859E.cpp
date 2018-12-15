#include<bits/stdc++.h>
 
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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 200000+5
using namespace std;

vi G[MAX],revG[MAX];
bitset<MAX> vis;
bitset<MAX> recStack;
bitset<MAX> mark;
bitset<MAX> curr;
int cycle;

void dfs(int u)
{
	if(!vis[u])
	{
		vis[u] = true;
		recStack[u] = true;
		rep(i,0,G[u].size())
			if(!vis[G[u][i]])
				dfs(G[u][i]);
			else if(recStack[G[u][i]])
				cycle=G[u][i];
	}
	recStack[u]=false;
}

int dfs1(int u,int p)
{
	if(p && u==cycle)
		return p;
	mark[u]=true;
	dfs1(G[u][0],p+1);
}

ll dfs2(int u)
{
	ll ret = 1;
	rep(i,0,revG[u].size())
	ret += dfs2(revG[u][i]);
	return ret;
}

int main()
{
	int n;
	si(n);
	curr.reset();
	rep(i,0,n)
	{
		int u,v;
		si(u); si(v);
		curr[u]=true;
		G[u].pb(v);
		revG[v].pb(u);
	}
	vis.reset();
	recStack.reset();
	mark.reset();
	ll ans = 1;
	rep(i,0,MAX)
	if(!vis[i])
	{
		cycle = -1;
		dfs(i);
		if(cycle>=0)
		{
			int len = dfs1(cycle,0);
			if(len>1)
			{
				ans*=2;
				ans%=MOD;
			}
		}
	}

	//prll(ans);

	rep(i,0,MAX)
	if(!curr[i])
	{
		ans*=dfs2(i);
		ans%=MOD;
	}

	prll(ans);

	return 0;
}