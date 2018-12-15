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
#define INF 400000000000000
#define MAX 100000+5
using namespace std;

vector<pair<ll,ll> > adj[MAX];
set<ll> s[MAX];
ll dis[MAX];

ll setdist(ll u,ll val)
{
	ll i;
	typeof(s[0].begin()) it=s[u].find(val);
	if(it==s[u].end())
		return val;
	ll prev=*it;
	it++;
	for(;it!=s[u].end();it++)
		if(*it!=prev+1)
			break;
		else
			prev++;
	return prev+1;
}

void dijkstra(ll src,ll n,ll dist[])
{
	ll d,idx,id,p;
	rep(i,0,n)
	dist[i]=INF;
	dist[src]=setdist(src,0);
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
			it=v.find(mp(dist[id],id));
			ll x=(id==n-1)?(p+d):setdist(id,p+d);
			if(dist[id]>x)
			{
				v.erase(it);
				dist[id]=x;
				v.insert(mp(dist[id],id));
			}
		}
	}
	return;
}

int main()
{
	ll n,m,u,v,w,p;
	sl(n); sl(m);
	while(m--)
	{
		sl(u); sl(v); sl(w);
		u--;
		v--;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	rep(i,0,n)
	{
		dis[i]=INF;
		sl(m);
		while(m--)
		{
			sl(p);
			s[i].insert(p);
		}
	}
	dijkstra(0,n,dis);
	ll ans=(dis[n-1]==INF)?-1:dis[n-1];
	prll(ans);
}