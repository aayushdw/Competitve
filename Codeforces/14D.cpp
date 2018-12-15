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
#define MAX 200+5
using namespace std;

vii E;
vi G[MAX];
int no,node,dmax;
bitset<MAX> vis;

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(!vis[u])
		{
			node=u;
			vis[u]=true;
			rep(i,0,G[u].size())
			if(!vis[G[u][i]] && G[u][i]!=no)
				q.push(G[u][i]);
		}
	}
}

void dfs(int u,int par,int dist)
{
	dmax=max(dmax,dist);
	rep(i,0,G[u].size())
	if(G[u][i]!=par && G[u][i]!=no)
		dfs(G[u][i],u,dist+1);
}

int main()
{
	int n,u,v,ans=0;
	si(n);
	rep(i,0,n-1)
	{
		si(u); si(v);
		E.pb(mp(u,v));
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i,0,n-1)
	{
		//printf("%d %d\n",E[i].F,E[i].S);
		no=E[i].F;
		vis.reset();
		bfs(E[i].S);
		dmax=0;
		dfs(node,no,0);
		int p=dmax;

		no=E[i].S;
		vis.reset();
		bfs(E[i].F);
		dmax=0;
		dfs(node,no,0);
		p*=dmax;

		ans=max(ans,p);
	}
	pr(ans);
	return 0;
}