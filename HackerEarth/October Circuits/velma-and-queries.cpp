#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
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
#define MAX 100000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bitset<MAX> vis;
vector<ll> adj[MAX];
map<ll,ll> m[MAX];
ll val[MAX];
ll lvl[MAX]={0};
void rec(ll p,ll l)
{
	//printf("%d\n",p);
	lvl[p]=l; vis[p]=true;
	vector<ll> v;
	rep(i,0,adj[p].size())
	{
		if(!vis[adj[p][i]])
			v.pb(adj[p][i]);
	}
	adj[p].clear();
	adj[p]=v;
	rep(i,0,adj[p].size())
	rec(adj[p][i],l+1);
}
void tree()
{
	vis.reset();
	rec(1,1);
}
ll query(ll u,ll l)
{
	if(lvl[u]==l)
		return val[u];
	map<ll,ll>::iterator it=m[u].find(l);
	if(it!=m[u].end())
		return it->second;
	ll ans=0;
	rep(i,0,adj[u].size())
	ans+=query(adj[u][i],l);
	m[u].insert(mp(l,ans));
	return ans;
}
int main()
{
	ll t,n,q,u,v,l;
	scll(t);
	while(t--)
	{
		scll(n); scll(q);
		rep(i,1,n+1)
		{
			scll(val[i]);
			adj[i].clear();
			m[i].clear();
		}
		rep(i,0,n-1)
		{
			scll(u); scll(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		tree();
		while(q--)
		{
			scll(u); scll(l);
			if(lvl[u]>l)
				prll(0ll);
			else
				prll(query(u,l));
		}
	}
	return 0;
}