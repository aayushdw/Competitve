#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
vector<vector<vector<ll> > > nodes;
ll val[MAX];
ll lvl[MAX]={0};
ll rmq[MAX][17];
void rec(ll p,ll l)
{
	lvl[p]=l; vis[p]=true;
	vector<ll> v;
	rep(i,0,adj[p].size())
	{
		if(!vis[adj[p][i]])
		{
			v.pb(adj[p][i]);
			rmq[p][0]+=val[adj[p][i]];
			nodes[p][0].pb(adj[p][i]);
		}
	}
	adj[p].clear();
	adj[p]=v;
	rep(i,0,adj[p].size())
	rec(adj[p][i],l+1);
}
void tree()
{
	vis.reset();
	rec(1,0);
}
void build(ll k,ll n)
{
	rep(i,1,n)
	{
		rep(j,0,nodes[i][k-1].size())
		{
			rmq[i][k]+=rmq[nodes[i][k-1][j]][k-1];
			rep(l,0,nodes[nodes[i][k-1][j]][k-1].size())
			nodes[i][k].pb(nodes[nodes[i][k-1][j]][k-1][l]);
		}
	}
}
ll query(ll u,ll d)
{
	ll p=(ll)(floor(log2(d)));
	if(1<<p==d)
		return rmq[u][p];
	else
	{
		ll ans=0;
		rep(i,0,nodes[u][p].size())
		ans+=query(nodes[u][p][i],d-(1<<p));
		return ans;
	}

}
int main()
{
	ll t,n,q,u,v,l;
	scll(t);
	while(t--)
	{
		scll(n); scll(q);
		nodes.clear();
		nodes.resize(n+1);
		rep(i,1,n+1)
		nodes[i].resize(17);
		rep(i,1,n+1)
		adj[i].clear(), scll(val[i]);
		rep(i,0,n-1)
		{
			scll(u); scll(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(rmq,0,sizeof(rmq));
		tree();
		rep(i,1,17)
		build(i,n);

        
		while(q--)
		{
			scll(u); scll(l);
			l--; l-=lvl[u];
			//printf("%lld %lld\n",u,l);
			if(l<0)
				printf("0\n");
			else if(l==0)
			    printf("%lld\n",val[u]);
			else
				printf("%lld\n",query(u,l));
		}
		
	}
	return 0;
}