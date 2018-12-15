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
#define INF 400000000000000
#define MAX 100+5
using namespace std;

vi G[MAX];
bitset<MAX> vis;
ll dist[MAX][MAX];
ll n,m,s;

bool dfs(ll u,ll p)
{
	vis[u]=true;
	rep(i,0,G[u].size())
	if(G[u][i]!=p)
	{
		if(vis[G[u][i]])
			return true;
		dfs(G[u][i],u);
	}
	return false;
}

void bellman_ford()
{
	rep(k,1,n+1)
	rep(i,1,n+1)
	rep(j,1,n+1)
	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main()
{
	ll u,v,cost;
	sl(n); sl(m); sl(s);
	rep(i,0,MAX)
	rep(j,0,MAX)
	dist[i][j]=INF;
	rep(i,0,MAX)
	dist[i][i]=0;
	while(m--)
	{
		sl(u); sl(v); sl(cost);
		if(u==v || dist[u][v]!=INF)
		{
			printf("YES");
			return 0;
		}
		dist[u][v]=cost;
		dist[v][u]=cost;
		G[u].pb(v);
		G[v].pb(u);
	}
	vis.reset();
	rep(i,1,n+1)
	if(!vis[i] && dfs(i,i))
	{
		printf("YES");
		return 0;
	}
	bellman_ford();
	rep(i,1,n+1)
	rep(j,1,n+1)
	if(dist[i][j]>=s && dist[i][j]<INF)
	{
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}