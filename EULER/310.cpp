#include <bits/stdc++.h>
 
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
#define MAX 100001
using namespace std;

vii vec[128];
vl c(128,0ll);
vi g(MAX);

int mex(vi &v)
{
	sort(all(v));
	unique(all(v));
	rep(i,0,v.size())
		if(i!=v[i])
			return i;
	return (int)v.size();
}

int getGrundy(int n)
{
	vi v;
	int i = 1;
	while(1)
	{
		int j = n - i*i;
		i++;
		if(j<0)
			break;
		v.pb(g[j]);
	}
	return g[n] = mex(v);
}

void pre()
{
	rep(i,0,128)
	rep(j,i,128)
		vec[i^j].pb(mp(i,j));
}

ll add(int n)
{
	ll ret = 0;
	rep(i,0,vec[n].size())
	{
		int f = vec[n][i].F;
		int s = vec[n][i].S;
		if(f!=s)
			ret += c[f]*c[s];
		else
			ret += (c[f]*(c[f]+1))/2;
	}
	return ret;
}

int main()
{
	pre();
	g[0] = 0;
	c[0]++;
	ll ans = 1;
	rep(i,1,MAX)
	{
		ll G = getGrundy(i);
		c[G]++;
		ans += add(G);
	}
	prll(ans);
	return 0;
}