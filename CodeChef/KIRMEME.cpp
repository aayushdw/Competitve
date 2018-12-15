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
#define MAXN 1000+5
#define LOGMAXN 10
#define MOD 1000000007
using namespace std;
// All pairs LCA source: https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
int T[MAXN];
vector<int> adj[MAXN];
int a[MAXN];
bitset<MAXN> vis;
int ans;
void tree(int p, int l)
{
	vis[p]=true;
	rep(i,0,adj[p].size())
		if(!vis[adj[p][i]])
			T[adj[p][i]]=p, tree(adj[p][i],l+1);
}
void solve(int u,int par,int prev,int len,int l,int r)
{
	if(vis[u])
		return;
	vis[u]=true;
	if(a[par]>a[u] && a[prev]>a[par])
		len++;
	printf("%d %d\n",u+1,len);
	if(len>=l && len<=r)
		ans++;
	solve(T[u],u,par,len,l,r);
	rep(i,0,adj[u].size())
	solve(adj[u][i],u,par,len,l,r);
}
int main()
{
	int t,n,l,r,u,v;
	sc(t);
	while(t--)
	{
		sc(n); sc(l); sc(r);
		rep(i,0,n)
		{
			sc(a[i]);
			adj[i].clear();
		}
		memset(T,0,sizeof(T));
		rep(i,0,n-1)
		{
			sc(u); sc(v);
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		vis.reset();
		T[0]=0;
		tree(0,0);
		ans=0;
		vis.reset();
		rep(i,0,n)
		{
			printf("%d\n",i+1);
			vis.reset();
			solve(i,i,i,0,l,r);
		}
		pr(ans);
	}
	return 0;
}