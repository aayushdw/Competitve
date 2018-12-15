#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 50000+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bitset<MAX> is,vis;
vector<pair<ll,ll> > adj[MAX];
ll numis[MAX];
ll ans;
ll tree(ll p)
{
	vis[p]=true;
	int c=is[p];
	rep(i,0,adj[p].size())
	if(!vis[adj[p][i].first])
		c+=tree(adj[p][i].first);
	return numis[p]=c;
}
ll getSum(ll p)
{
	vis[p]=true;
	int a=adj[p].size(),q=is[p]?numis[p]-1:numis[p];
	ll ret=0,x;
	rep(i,0,a)
	{
		if(numis[adj[p][i].first] && !vis[adj[p][i].first])
		{
			x=getSum(adj[p][i].first);
			ret+=numis[adj[p][i].first]*adj[p][i].second+x;
			if(is[p])
				ans+=numis[adj[p][i].first]*adj[p][i].second+x;
			ans+=(q-numis[adj[p][i].first])*(numis[adj[p][i].first]*adj[p][i].second+x);
		}
	}
	return ret;
}
int main()
{
	ll t,n,m,c,u,v,l,p;
	ll r,g,q;
	scll(t);
	while(t--)
	{
		scll(n); scll(m);
		rep(i,1,n+1)
		adj[i].clear();
		rep(i,1,n)
		{
			scll(u); scll(v); scll(l);
			adj[u].pb(mp(v,l));
			adj[v].pb(mp(u,l));
		}
		is.reset();
		vis.reset();
		rep(i,0,m)
		{
			scll(p);
			is[p]=true;
		}
		tree(1);
		vis.reset();
		q=m*m; ans=0;
		getSum(1);
		ans*=2;
		g=__gcd(ans,q);
		printf("%lld %lld\n",ans/g,(m*m)/g);
	}
	return 0;
}