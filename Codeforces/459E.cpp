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
#define MAX 300000+5
using namespace std;

vector< pair< int,ii > > E;
int curr[MAX][2], prev[MAX][2];

int main()
{
	int n,m,u,v,w;
	si(n); si(m);
	rep(i,0,m)
	{
		si(u); si(v);
		si(w);
		E.pb(mp(w,mp(u,v)));
	}
	sort(all(E));
	clr(curr); clr(prev);
	rep(i,0,m)
	{
		w=E[i].F;
		u=E[i].S.F;
		v=E[i].S.S;
		if(curr[u][0]<w)
		{
			if(curr[v][1]>=curr[u][1]+1)
				continue;
			if(curr[v][0]!=w)
			{
				prev[v][0]=curr[v][0];
				prev[v][1]=curr[v][1];
			}
			curr[v][0]=w;
			curr[v][1]=curr[u][1]+1;
		}
		else
		{
			if(curr[v][1]>=prev[u][1]+1)
				continue;
			if(curr[v][0]!=w)
			{
				prev[v][0]=curr[v][0];
				prev[v][1]=curr[v][1];
			}
			curr[v][0]=w;
			curr[v][1]=prev[u][1]+1;
		}
	}
	int ans=0;
	rep(i,1,n+1)
	ans=max(ans,curr[i][1]);
	pr(ans);
	return 0;
}