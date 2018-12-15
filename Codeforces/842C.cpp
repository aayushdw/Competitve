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
#define MAX 200000+5
using namespace std;

int a[MAX];
vi G[MAX];
vi d[MAX];
int ans[MAX]={0},c[MAX]={0};
bitset<MAX> vis;

void pre()
{
	rep(i,1,MAX)
		for(int j=i;j<MAX;j+=i)
			d[j].pb(i);
	return;
}

void dfs(int u, int par, int idx)
{
	vis[u] = true;

	rep(i,0,d[a[u]].size())
		c[d[a[u]][i]]++;

	rep(i,0,d[a[u]].size())
		if(c[d[a[u]][i]]>=idx-1)
			ans[u] = max(ans[u],d[a[u]][i]);

	rep(i,0,d[a[par]].size())
		if(c[d[a[par]][i]]>=idx-1)
			ans[u] = max(ans[u],d[a[par]][i]);

	rep(i,0,G[u].size())
		if(!vis[G[u][i]])
			dfs(G[u][i],u,idx+1);

	rep(i,0,d[a[u]].size())
		c[d[a[u]][i]]--;
}

int main()
{
	pre();
	int n;
	cin>>n;
	rep(i,1,n+1)
		si(a[i]);
	rep(i,1,n)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	vis.reset();
	dfs(1,1,0);
	rep(i,1,n+1)
	printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}