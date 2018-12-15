#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
vector<pair<ll,ll> > adj[MAX];
ll dis[MAX],path[MAX];
void dijkstra(ll src,ll n,ll dist[])
{
	ll d,idx,id,p;
	rep(i,0,n)
	{
		dist[i]=INF;
		path[i]=INF;
	}
	dist[src]=0;
	set<pair<ll,ll> > v;
	typeof(v.begin()) it;
	rep(i,0,n)
	v.insert(mp(dist[i],i));
	while(v.size())
	{
		it=v.begin();
		d=it->first;
		idx=it->second;
		v.erase(it);
		rep(i,0,adj[idx].size())
		{
			id=adj[idx][i].first;
			p=adj[idx][i].second;
			if(dist[id]>p+d)
			{
				it=v.find(mp(dist[id],id));
				v.erase(it);
				dist[id]=p+d;
				path[id]=idx;
				v.insert(mp(dist[id],id));
			}
		}
	}
	return;
}
int main()
{
	ll n,m,x,y,p,ans;
	scll(n);
	rep(i,0,n-1)
	{
		adj[i].pb(mp(i+1,1));
		adj[i+1].pb(mp(i,1));
	}
	rep(i,0,n)
	{
		scll(p);
		p--;
		adj[i].pb(mp(p,1));
	}
	dijkstra(0,n,dis);
	rep(i,0,n)
	printf("%lld ",dis[i]);
	return 0;
}
