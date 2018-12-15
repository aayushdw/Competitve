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
#define INF 2e13
#define MAX 100000+5
using namespace std;

vl G[MAX];
vl child[MAX];
vl v(MAX);
bitset<MAX> vis;

bool isOverflow(ll a,ll b)
{
	return false;
}

ll lcm(ll a,ll b)
{
	if(!a || !b)
		return 0;
	ll g = __gcd(a,b);
	return a*b/g;
}

ll magik(ll u)
{
	vis[u] = true;
	ll ret = 1;
	rep(i,0,G[u].size())
	if(!vis[G[u][i]])
	{
		child[u].pb(G[u][i]);
		ll x = magik(G[u][i]);
		if(isOverflow(ret,x))
			ret = 0;
		else
			ret = lcm(ret,x);
	}
	// printf("%lld %lld\n",u,ret);
	if(child[u].empty())
		return 1;
	return ret*((ll)child[u].size());
}

bool check(ll num,ll u)
{
	if(child[u].empty())
		return num<=v[u];
	int n = child[u].size();
	if(num%n)
		return false;
	bool f = true;
	rep(i,0,n)
		f &= check(num/n,child[u][i]);
	return f;
}

int main()
{
	ll n;
	sl(n);
	rep(i,1,n+1)
		sl(v[i]);
	rep(i,0,n-1)
	{
		ll u,v;
		sl(u); sl(v);
		G[u].pb(v);
		G[v].pb(u);
	}

	// cout<<endl;
	vis.reset();
	ll num = magik(1);

	// prll(num);
	// return 0;

	ll tot = 0;
	rep(i,1,n+1)
		tot += v[i];

	if(!num)
	{
		prll(tot);
		return 0;
	}

	ll low = 0 , high = tot/num;
	while(low+1<high)
	{
		ll mid = (low+high)>>1;
		// printf("(%lld %d)\n",num*mid,(int)check(num*mid,1));
		if(check(num*mid,1))
			low = mid;
		else
			high = mid-1;
	}
	if(check(num*high,1))
		prll(tot-num*high);
	else
		prll(tot-num*low);
	return 0;
}