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
#define lb lower_bound
#define ub upper_bound
 
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

vector< ii > G[MAX];
ll ans[MAX];
bitset<MAX> vis;
ll a[MAX];

set<ll> dfs(ll u)
{
	vis[u] = true;
	set<ll> s;
	rep(i,0,G[u].size())
		if(!vis[G[u][i].F])
		{
			set<ll> temp = dfs(G[u][i].F);
			tr(it,temp)
				s.insert(*it+G[u][i].S);
		}
	s.insert(a[u]);
	ans[u] = s.size();
	return s;
}

int main()
{
	ll n;
	sl(n);
	rep(i,0,n-1)
	{
		ll x,y,c;
		sl(x); sl(y); sl(c);
		x--; y--;
		G[y].pb(mp(x,c));
		G[x].pb(mp(y,c));
	}
	rep(i,0,n)
		sl(a[i]);
	vis.reset();
	dfs(0);
	rep(i,0,n)
		prll(ans[i]);
	return 0;
}