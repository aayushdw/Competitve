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

class DSU
{
	public:
	vl par,rank,sum,val,flag;
	void init(ll n)
	{
		flag.assign(n,1);
		val.assign(n,0);
		par.assign(n,0);
		rank.assign(n,1);
		sum.assign(n,0);
		rep(i,0,n)
		par[i]=i;
	}
	ll find(ll u)
	{	return (par[u]==u)?u:find(par[u]);	}
	ll getSum(ll u)
	{	return (par[u]==u)?0:sum[u]^getSum(par[u]);	}
	void unite(ll x,ll v,ll val)
	{
		x=find(x); v=find(v);
		if(x==v) return;
		if(rank[x]>rank[v]) swap(x,v);
		par[x]=v;
		rank[v]+=rank[x];
		sum[x]=val;
	}
};

int main()
{
	ll n,m;
	DSU forest;
	sl(n); sl(m);
	forest.init(n+1);
	rep(i,1,n+1)
		sl(forest.val[i]);
	while(m--)
	{
		ll type,x;
		sl(type); sl(x);
		if(type == 1)
		{
			sl(forest.val[x]);
		}
		else if(type == 2)
		{
			ll y; sl(y);
			if(forest.find(x)==forest.find(y))
			{
				if(forest.getSum(x)==forest.getSum(y))
					forest.flag[forest.find(x)] = 0;
			}
			else
			{
				if(forest.getSum(x)==forest.getSum(y))
					forest.unite(x,y,1);
				else
					forest.unite(x,y,0);
			}
		}
		else
		{
			ll y,v;
			sl(y); sl(v);
			if(forest.find(x)!=forest.find(y) || !forest.flag[forest.find(x)])
				pr(0);
			else
			{
				if(forest.getSum(x)!=forest.getSum(y))	printf("-");
				ll num = forest.val[x]*v;
				ll den = forest.val[y];
				ll gcd = __gcd(num,den);
				printf("%lld/%lld\n",num/gcd,den/gcd);
			}
		}
	}
	return 0;
}