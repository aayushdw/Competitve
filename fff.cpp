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
#define MAX 400000+5
using namespace std;

ll fact[MAX];
ll invFact[MAX];
vl G[MAX];

ll powmod(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

void pre()
{
	fact[0] = 1;
	invFact[0] = 1;
	rep(i,1,MAX)
	{
		fact[i] = fact[i-1] * i;
		invFact[i] = invFact[i-1] * powmod( i, MOD-2, MOD );
		fact[i] %= MOD;
		invFact[i] %= MOD;
	}
	return;
}

ll nCr( ll n, ll r )
{
	ll ret = fact[n];
	ret *= invFact[r];
	ret %= MOD;
	ret *= invFact[n-r];
	ret %= MOD;
	return ret;
}

pll mergeNodes( ll s1, ll n1, ll s2, ll n2 )
{
	pll ret = mp( s1+s2, (n1*n2)%MOD );
	ret.second *= nCr( s1+s2, s1 );
	ret.second %= MOD;
	return ret;
}

pll foo( ll u )
{
	if(G[u].empty())
		return( mp( 1ll,1ll ) );
	pll ret = mp( 0ll, 1ll );
	rep(i,0,G[u].size())
	{
		pll temp = foo( G[u][i] );
		ret = mergeNodes( ret.first, ret.second, temp.first, temp.second );
	}
	ret.first++;
	return ret;
}

int main()
{
	pre();
	ll t;
	sl(t);
	while(t--)
	{
		rep(i,0,MAX)
			G[i].clear();
		ll n,m;
		sl(n); sl(m);
		vl par(n+1,0);
		while(m--)
		{
			ll u,v;
			sl(u); sl(v);
			G[u].pb(v);
			par[v] = u;
		}
		rep(i,1,n+1)
			if(!par[i])
				G[0].pb(i);
		prll( foo(0).second );
	}

	return 0;
}