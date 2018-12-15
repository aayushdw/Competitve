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

bitset<MAX> vis;
int ispar[MAX];
bitset<MAX> temp_vis;
bitset<MAX> cycle;
int ans1=0;
int par[MAX];

void dfs(int u)
{
	if(temp_vis[u])
		cycle[u]=true;
	if(vis[u])
		return;
	vis[u]=true;
	temp_vis[u]=true;
	dfs(par[u]);
}

int getCycle(int u)
{
	int v=par[u],ret=1;
	while(v!=u)
	{
		ret++;
		v=par[v];
	}
	return ret;
}

int main()
{
	int n;
	si(n);
	clr(ispar);
	rep(i,1,n+1)
	{
		si(par[i]);
		if(i!=par[i])
		ispar[par[i]]++;
	}
	int x=0;
	vis.reset();
	rep(i,1,n+1)
	if(!ispar[i])
	{
		temp_vis.reset();
		x++;
		dfs(i);
	}
	rep(i,1,n+1)
	if(!vis[i])
	{
		temp_vis.reset();
		x++;
		dfs(i);
	}
	int y=n;
	rep(i,1,n+1)
	if(cycle[i])
		y-=getCycle(i)-1;
	
	printf("%d %d",x,y);

	return 0;
}