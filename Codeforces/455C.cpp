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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 300000+5
using namespace std;

bitset<MAX> vis;
bitset<MAX> tempvis;
vi G[MAX];
int last_node,dia;
int D[MAX];

class DSU
{
	public:
	vi par,rank;
	void init(int n)
	{
		par.assign(n,0);
		rank.assign(n,1);
		rep(i,0,n)
		par[i]=i;
	}
	int find(int u)
	{	return (par[u]==u)?u:find(par[u]);	}
	void unite(int x,int v,int val)
	{
		x=find(x); v=find(v);
		if(x==v) return;
		if(rank[x]>rank[v]) swap(x,v);
		par[x]=v;
		rank[v]+=rank[x];
		D[v]=max(max(D[v],D[x]),(D[x]+1)/2+(D[v]+1)/2+1);
	}
};

void bfs(int u,int fill)
{
	list< ii > queue;
	queue.pb(mp(u,0));
	while(!queue.empty())
	{
		u=queue.front().F;
		int level=queue.front().S;
		queue.pop_front();
		vis[u]=true;
		tempvis[u]=true;
		D[u]=fill;
		last_node=u;
		dia=level;
		rep(i,0,G[u].size())
		if(!tempvis[G[u][i]])
			queue.pb(mp(G[u][i],level+1));
	}
}

DSU forest;

void getDia(int u)
{
	tempvis.reset();
	bfs(u,0);
	u=last_node;
	tempvis.reset();
	bfs(u,0);
	D[forest.find(u)]=dia;
}

int main()
{
	int n,m,q,u,v,x,y,p;
	si(n); si(m); si(q);
	forest.init(n+1);
	rep(i,0,m)
	{
		si(u); si(v);
		G[u].pb(v);
		G[v].pb(u);
		forest.unite(u,v,0);
	}
	clr(D);
	rep(i,1,n+1)
	if(!vis[i])
	getDia(i);
	/*rep(i,1,n+1)
	printf("%d ",D[i]);
	printf("\n");*/
	while(q--)
	{
		si(p);
		if(p==1)
		{
			si(x);
			pr(D[forest.find(x)]);
		}
		else
		{
			si(x); si(y);
			forest.unite(x,y,0);
		}
		/*rep(i,1,n+1)
		printf("%d ",D[i]);
		printf("\n");*/
	}
	return 0;
}