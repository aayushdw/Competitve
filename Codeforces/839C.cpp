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
#define MAX 100000+5
using namespace std;

vi G[MAX];
bitset<MAX> vis;
double ans[MAX];

void dfs(int u, int len, double p)
{
	if(vis[u])
		return;
	vis[u]=true;
	int n;
	if(u==1)
		n=G[u].size();
	else
		n=G[u].size()-1;
	if(n)
	{
		rep(i,0,G[u].size())
		dfs(G[u][i],len+1,p/n);
	}
	else
	{
		ans[u] = p*len;
	}
	return;
}

int main()
{
	int n,u,v;
	si(n);
	rep(i,0,n-1)
	{
		si(u); si(v);
		G[u].pb(v);
		G[v].pb(u);
	}
	clr(ans);
	vis.reset();
	dfs(1,0,1.0);
	double ret = 0.0;
	rep(i,0,n+1)
	ret+=ans[i];
	printf("%0.9lf",ret);
	return 0;
}