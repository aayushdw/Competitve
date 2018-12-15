#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
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
#define MAX 200000+5
#define MAXN 100
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them

vector<int> adj[MAXN],cc[MAXN];
set<pair<int,int> > bridge;
bool used[MAXN];
int timer;
void dfsBridges(int u,int tin[],int fup[],int p)
{
	int to;
	used[u]=true;
	tin[u]=fup[u]=timer++;
	rep(i,0,adj[u].size())
	{
		to=adj[u][i];
		if(to==p)
			continue;
		if(used[to])
			fup[u]=min(fup[u],tin[to]);
		else
		{
			dfsBridges(to,tin,fup,u);
			fup[u]=min(fup[u],fup[to]);
			if(fup[to]>tin[u])
				bridge.insert(mp(u,to));
		}
	}
}
void getBridges(int n)
{
	int p=-1;
	bridge.clear();
	int *tin= new int[n];
	int *fup= new int[n];
	rep(i,0,n)
	used[i]=false;
	timer=0;
	rep(i,0,n)
	if(!used[i])
	dfsBridges(i,tin,fup,p);
}
void removeBridges()
{
	int u,v;
	tr(bridge,it)
	{
		u=it->first;
		v=it->second;
		tr(adj[u],i)
		if(*i==v)
		{
			adj[u].erase(i);
			break;
		}
		tr(adj[v],i)
		if(*i==u)
		{
			adj[v].erase(i);
			break;
		}
	}
}
int main()
{
	int n,m,u,v,ans,t;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		rep(i,0,n)
		adj[i].clear();
		while(m--)
		{
			sc(u); sc(v); u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		getBridges(n);
		removeBridges();
		typeof(bridge.begin()) it;
		tr(bridge,it)
		printf("%d %d\n",it->first,it->second);
		rep(i,0,n)
		{
			printf("%d -> ",i);
			rep(j,0,adj[i].size())
			printf("%d ",adj[i][j]);
			printf("\n");
		}
	}
	return 0;
}