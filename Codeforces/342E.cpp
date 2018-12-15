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
#define INF 100000000
#define MAX 100000+5
#define LOGMAX 20
#define MOD 1000000007
using namespace std;
set<int> adj[MAX];
int sub[MAX], level[MAX],dp[LOGMAX][MAX],ans[MAX],par[MAX];
void dfs0(int u,int p)
{
	typeof(adj[0].begin()) it;
	for(it=adj[u].begin();it!=adj[u].end();it++)
		if(*it!=p)
		{
			dp[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it,u);
		}
}
void tree()
{
	level[0]=0;
	dp[0][0]=0;
	dfs0(0,0);
	rep(i,1,LOGMAX)
		rep(j,0,MAX)
			dp[i][j]=dp[i-1][dp[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);
	int d = level[b]-level[a];

	for(int i=0;i<LOGMAX;i++)
		if(d&(1<<i))
			b=dp[i][b];

	if(a==b)
		return a;

	for(int i=LOGMAX-1;i>=0;i--)
		if(dp[i][a]!=dp[i][b])
			a=dp[i][a],b=dp[i][b];

	return dp[0][a];
}
int dist(int u,int v)
{	return level[u] + level[v] - 2*level[lca(u,v)];	}

int nn;
void dfs1(int u,int p)
{
	typeof(adj[0].begin()) it;
	sub[u]=1;
	nn++;
	for(it=adj[u].begin();it!=adj[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	typeof(adj[0].begin()) it;
	for(it=adj[u].begin();it!=adj[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
		{
			//printf("Assumption %d, Neighbour %d, SubtreeSize = %d\n",u,*it,sub[*it]);
			return dfs2(*it,u);
		}
	return u;
}
void decompose(int root,int p)
{
	typeof(adj[0].begin()) it;
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	(p==-1)?(par[centroid]=centroid):(par[centroid]=p);
	for(it=adj[centroid].begin();it!=adj[centroid].end();it++)
	{
		adj[*it].erase(centroid);
		decompose(*it,centroid);
	}
	adj[centroid].clear();
}
void update(int u)
{
	//printf("Update = %d\n",u+1);
	int x = u;
	while(1)
	{
		ans[x] = min(ans[x],dist(x,u));
		if(x==par[x])
			break;
		x = par[x];
	}
}
int query(int u)
{
	int x = u;
	int ret=INF;
	while(1)
	{
		ret = min(ret,dist(u,x) + ans[x]);
		if(x==par[x])
			break;
		x = par[x];
	}
	return ret;
}
int main()
{
	int n,q,u,v;
	sc(n); sc(q);
	rep(i,0,n-1)
	{
		sc(u); sc(v);
		u--; v--;
		adj[u].insert(v); adj[v].insert(u);
	}
	tree();
	decompose(0,-1);
	rep(i,0,n)
	ans[i]=INF;
	update(0);
	while(q--)
	{
		sc(u); sc(v);
		u--; v--;
		if(u)
			printf("%d\n",query(v));
		else
			update(v);
	}
	return 0;
}