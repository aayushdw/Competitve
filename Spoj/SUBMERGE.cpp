#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
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
#define MAX 200000+5
#define MAXN 10000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them

vector<int> adj[MAXN];
bool used[MAXN],isCutpoint[MAXN];
int timer;
void dfsCutVertices(int u,int tin[],int fup[],int p)
{
	int to;
	used[u]=true;
	tin[u]=fup[u]=timer++;
	int children=0;
	rep(i,0,adj[u].size())
	{
		to=adj[u][i];
		if(used[to])
			fup[u]=min(fup[u],tin[to]);
		else
		{
			dfsCutVertices(to,tin,fup,u);
			fup[u]=min(fup[u],fup[to]);
			if(fup[to]>=tin[u] && p!=-1)
				isCutpoint[u]=true;
			++children;
		}
	}
	if(p==-1 && children>1)
		isCutpoint[u]=true;
}
void getCutVertices(int u,int n)
{
	int p=-1;
	int *tin= new int[n];
	int *fup= new int[n];
	rep(i,0,n)
	used[i]=false, isCutpoint[i]=false;
	timer=0;
	dfsCutVertices(u,tin,fup,p);
}
int main()
{
	int n,m,u,v,ans;
	while(1)
	{
		sc(n); sc(m); ans=0;
		if(n==0 && m==0)
			return 0;
		rep(i,0,n)
		adj[i].clear();
		while(m--)
		{
			sc(u); sc(v); u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		getCutVertices(0,n);
		rep(i,0,n)
		ans+=isCutpoint[i];
		pr(ans);
	}
	return 0;
}