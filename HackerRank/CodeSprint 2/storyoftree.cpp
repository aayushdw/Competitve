#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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

int n,t,p,g,k,ans=0,num=0;

bitset<MAX> vis;
vi adj[MAX];
set<int> guess[MAX];

void dfs1(int u)
{
	vis[u]=true;
	rep(i,0,adj[u].size())
	if(!vis[adj[u][i]])
	{
		if(guess[adj[u][i]].find(u)!=guess[adj[u][i]].end())
			num++;
		dfs1(adj[u][i]);
	}
}

void dfs2(int u)
{
	vis[u]=true;
	rep(i,0,adj[u].size())
	{
		int v=adj[u][i];
		if(!vis[v])
		{
			if(guess[u].find(v)!=guess[u].end())
				num++;
			if(guess[v].find(u)!=guess[v].end())
				num--;
			if(num>=k)
				ans++;

			printf("%d %d\n",v,ans);

			dfs2(v);

			if(guess[u].find(v)!=guess[u].end())
				num--;
			if(guess[v].find(u)!=guess[v].end())
				num++;
		}
	}
}

int main()
{
	int u,v;
	si(t);
	while(t--)
	{
		num=0; ans=0;
		si(n);
		rep(i,0,n+1)
		{
			adj[i].clear();
			guess[i].clear();
		}
		rep(i,0,n-1)
		{
			si(u); si(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		si(g); si(k);
		rep(i,0,g)
		{
			si(u); si(v);
			guess[v].insert(u);
		}
		vis.reset();
		dfs1(1);
		vis.reset();
		dfs2(1);
		p=__gcd(n,ans);
		printf("%d %d\n",ans/p,n/p);
	}
	return 0;
}