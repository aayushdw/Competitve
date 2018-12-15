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
#define MAX 300000+5
using namespace std;

#define NUMPRIME 2

ll MODS[NUMPRIME] = {1000000007,1000000009};
ll power[2][MAX];

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

vl g[2][MAX];
bitset<MAX> vis;
unordered_map<ll,ll> s[2];

void add(map<ll,ll> &m,ll num)
{
	auto it = m.find(num);
	if(it!=m.end())
		it->S++;
	else
		m.insert(mp(num,1));
}

ll pre(ll graph,ll u)
{
	vis[u] = true;
	ll hash = powmod(u,u,MOD);
	// vl hash(NUMPRIME);
	// rep(i,0,NUMPRIME)
	// 	hash[i] = u;
	rep(i,0,g[graph][u].size())
		if(!vis[g[graph][u][i]])
		{
			// vl temp = pre(graph,g[graph][u][i]);
			// rep(i,0,NUMPRIME)
			// {
			// 	hash[i] += temp[i];
			// 	hash[i] %= MODS[i];
			// }
			hash += pre(graph,g[graph][u][i]);
		}
	if(u!=1)
	{
		// rep(i,0,NUMPRIME)
			add(s[1],hash);
	}
	return hash;
}

int main()
{
	rep(i,1,MAX)
		power[0][i] = powmod(i,i,MODS[0]);
	rep(i,1,MAX)
		power[1][i] = powmod(i,i,MODS[1]);
	ll n;
	sl(n);
	rep(i,2,n+1)
	{
		ll x;
		sl(x);
		g[0][x].pb(i);
		g[0][i].pb(x);
	}
	rep(i,2,n+1)
	{
		ll x;
		sl(x);
		g[1][x].pb(i);
		g[1][i].pb(x);
	}
	vis.reset();
	pre(0ll,1ll);
	vis.reset();
	pre(1ll,1ll);

	// tr(it,s[0])
	// 	printf("%lld ",it->F);
	// printf("\n");

	// tr(it,s[1])
	// 	printf("%lld ",it->F);
	// printf("\n");

	ll ans = 0;

	tr(it,s[0])
	{
		ll num = it->S;
		auto iter = s[1].find(it->F);
		if(iter!=s[1].end())
		{
			num *= iter->S;
			ans += num;
		}
	}
	prll(ans);
	return 0;
}