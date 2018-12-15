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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

bitset<MAX> vis;

class DSU
{
	public:
	vl par,rank,sum;
	void init(ll n)
	{
		par.assign(n,0);
		rank.assign(n,1ll);
		sum.assign(n,0);
		rep(i,0,n)
		par[i]=i;
	}
	ll find(ll u)
	{	return (par[u]==u)?u:find(par[u]);	}
	void unite(ll x,ll v)
	{
		x=find(x); v=find(v);
		if(x==v)
		{
			sum[x]++;
			return;
		}
		if(rank[x]>rank[v]) swap(x,v);
		par[x]=v;
		rank[v]+=rank[x];
		sum[v]+=sum[x]+1;
		return;
	}
};

int main()
{
	ll n,m,u,v;
	sl(n); sl(m);
	DSU d;
	d.init(n+1);
	rep(i,0,m)
	{
		sl(u); sl(v);
		d.unite(u,v);
	}
	bool f=true;
	ll h=0,c=0;
	vl vec;
	
	rep(i,1,n+1)
		if(i==d.find(i))
		{
			ll _n = d.rank[i];
			ll _m = d.sum[i];
			//printf("%d %lld %lld\n",u,_n,_m);
			if(_n==1)
				continue;
			if(_m>=_n+1)
				f=false;
			else if(_m==_n)
			{
				vec.pb(_n);
				c++;
			}
			else
				vec.pb(_n);
			h+= _n*(_n-1);
		}

	if(!f || c>=2)
		prll(h);
	else
	{
		sort(all(vec));
		if(vec.size()==1)
		{
			ll _n = vec[0];
			h-= 2*(_n-1 );
			if(c==0)
			{
				_n--;
				h-= 2*(_n-1 );
			}
		}
		else
		{
			ll _n = vec[0];
			h-= 2*(_n-1 );
			if(_n >= 3)
				vec[1]=_n-1;
			if(c==0)
			{
				_n = vec[1];
				h-= 2*(_n-1 );
			}
		}
		prll(h);
	}
	return 0;
}