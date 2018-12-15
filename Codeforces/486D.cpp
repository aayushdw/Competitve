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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<ll>
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
#define MAX 2000+5
using namespace std;

vl adj[MAX];
ll a[MAX];

ll dfs(ll root,ll u,ll p,ll low,ll high)
{
	if(a[u]<low || a[u]>high)
		return 0;
	if( u!=p && a[u]==low && root>u)
	{
		//printf("node=%lld , parent=%lld\n",u,p);
		return 0;
	}
	//printf("%lld %lld\n",u,p);
	ll ret=1;
	rep(i,0,adj[u].size())
	if(adj[u][i]!=p)
	{
		ret*=dfs(root,adj[u][i],u,low,high)+1;
		ret%=MOD;
	}
	return ret;
}

int main()
{
	ll d,n,u,v;
	sl(d); sl(n);
	rep(i,1,n+1)
	sl(a[i]);
	rep(i,1,n)
	{
		sl(u); sl(v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans=0;
	rep(i,1,n+1)
	{
		//ans+=dfs(i,i,a[i],a[i]+d);
		//printf("v=%lld\n",i);
		ans+=dfs(i,i,i,a[i],a[i]+d);
		//printf("num=%lld\n",num);
	}
	ans%=MOD;
	prll(ans);
	return 0;
}