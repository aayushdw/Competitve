#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define INF 1000000000000
#define MAX 100+5
using namespace std;

ll c[MAX][MAX],dist[MAX][MAX],ans[5000+5];
vector< pll > f;

void initialise()
{
	rep(i,0,MAX)
	rep(j,0,MAX)
	c[i][j]=INF, dist[i][j]=INF;
	rep(i,0,MAX)
	c[i][i]=0;

	f.clear();
	f.pb(mp(0ll,0ll));
}

void floyd(ll n)
{
	rep(i,1,n+1)
	rep(j,1,n+1)
	dist[i][j]=c[i][j];

	rep(k,1,n+1)
	rep(i,1,n+1)
	rep(j,1,n+1)
	if(dist[i][k]+dist[k][j]<dist[i][j])
		dist[i][j]=dist[i][k]+dist[k][j];
}

ll rec(ll n)
{
	//printf("%lld\n",n);
	if(ans[n]>0)
		return ans[n];
	if(n==1)
		return dist[1][f[1].F]+dist[f[1].F][f[1].S];
	if(n==2)
		return min(rec(n-1)+dist[f[1].S][f[2].F]+dist[f[2].F][f[2].S] , dist[1][f[1].F]+dist[f[1].F][f[2].F]+dist[f[2].F][f[1].S]+dist[f[1].S][f[2].S]);

	ll ret=rec(n-1)+dist[f[n-1].S][f[n].F]+dist[f[n].F][f[n].S];
	ret=min(ret,rec(n-2)+dist[f[n-2].S][f[n-1].F]+dist[f[n-1].F][f[n].F]+dist[f[n].F][f[n-1].S]+dist[f[n-1].S][f[n].S]);
	return ans[n]=ret;
}

ll solve(ll n, ll k)
{
	floyd(n);
	memset(ans,-1,sizeof(ans));
	ll ret=rec(k);
	if(ret>=INF)
		return -1;
	else
		return ret;
}

int main()
{
	ll t,n,m,k,u,v,cost;
	sl(t);
	rep(tt,1,t+1)
	{
		initialise();
		sl(n); sl(m); sl(k);
		rep(i,0,m)
		{
			sl(u); sl(v); sl(cost);
			c[u][v]=min(cost,c[u][v]);
			c[v][u]=min(cost,c[v][u]);
		}
		rep(i,0,k)
		{
			sl(u); sl(v);
			f.pb(mp(u,v));
		}
		printf("Case #%lld: %lld\n",tt,solve(n,k));
	}
	return 0;
}