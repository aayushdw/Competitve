#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define MAX 100000+5
using namespace std;
vector<ll> adj[MAX];
ll a[MAX];
bool isBipartite(ll src)
{
	a[src]=1;
	queue<ll> q;
	q.push(src);
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		
		rep(i,0,adj[u].size())
		{
			ll p=adj[u][i];
			if(a[p]==-1)
			{
				a[p]=1-a[u];
				q.push(p);
			}
			else if(a[p]==a[u])
			return false;
		}
	}
	return true;
}
int main()
{
	ll n,m,x,y,p,ans,src;
	scll(n); scll(m);
	rep(i,0,m)
	{
		scll(x); scll(y);
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(i,0,n)
	a[i]=-1;
	bool f=true;
	rep(i,0,n)
	{
	    if(a[i]!=-1 || !adj[i].size())
	    continue;
	    f=isBipartite(i);
	    if(!f)
	    break;
	}

	if(!f)
	printf("-1");
	else
	{
		vector<ll> v1,v2;
		rep(i,0,n)
		if(a[i]==0)
		v1.pb(i);
		else if(a[i]==1)
		v2.pb(i);
		
		printf("%d\n",v1.size());
		rep(i,0,v1.size())
		printf("%lld ",v1[i]+1);
		printf("\n");
		
		printf("%d\n",v2.size());
		rep(i,0,v2.size())
		printf("%lld ",v2[i]+1);
		
	}
	return 0;
}
