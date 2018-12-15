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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define MAX 300000+5
using namespace std;

vl g1[MAX];
vl g2[MAX];
bitset<MAX> vis;
unordered_map<ll,ll> m1,m2;
int p[MAX],q[MAX];

void add(unordered_map<ll,ll> &m,ll num)
{
	auto it = m.find(num);
	if(it!=m.end())
		it->S++;
	else
		m.insert(mp(num,1));
}

ll dfs1(ll u)
{
	vis[u] = true;
	ll hash1 = u , hash2 = u;
	rep(i,0,g1[u].size())
		if(!vis[g1[u][i]])
		{
			ll x = dfs1(g1[u][i]);
			hash1 ^= x; hash1 %= MOD;
			// hash2 ^= x.S;
		}
	ll ret = hash1;
	if(u!=1)
		add(m1,ret);
	return ret;
}

ll dfs2(ll u)
{
	vis[u] = true;
	ll hash1 = u , hash2 = u;
	rep(i,0,g2[u].size())
		if(!vis[g2[u][i]])
		{
			ll x = dfs2(g2[u][i]);
			hash1 ^= x; hash1 %= MOD;
			// hash2 ^= x.S;
		}
	ll ret = hash1;
	if(u!=1)
		add(m2,ret);
	return ret;
}

int main()
{
	ll n;
	sl(n);
	rep(i,2,n+1)
		si(p[i]);
	rep(i,2,n+1)
		si(q[i]);
	rep(i,2,n+1)
	{
		g1[i].pb(p[i]);
		g1[p[i]].pb(i);

		g2[i].pb(q[i]);
		g2[q[i]].pb(i);
	}

	vis.reset();
	dfs1(1ll);
	vis.reset();
	dfs2(1ll);

	ll ans = 0;

	tr(it,m1)
	{
		auto iter = m2.find(it->F);
		if(iter!=m2.end())
			ans += (it->S)*(iter->S);
	}

	prll(ans);

	return 0;
}