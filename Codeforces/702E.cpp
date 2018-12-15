#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

ll par[MAX],wt[MAX];
vector< pair< ll,pll > > a,b;

void foo(ll k,ll n)
{
	if(k==1)
	{
		b=a;
		return;
	}
	vector< pair< ll,pll > > vf,vs;
	if(k%2)
	{
		foo(k-1,n);
		vf=b;
		vs=a;
	}
	else
	{
		foo(k/2,n);
		vf=b;
		vs=b;
	}
	ll x,xf,y,z;
	vector< pair< ll,pll > > temp;
	rep(i,0,n)
	{
		x=vf[i].F;
		xf=vs[x].F;
		y=vf[i].S.F+vs[x].S.F;
		z=min(vf[i].S.S,vs[x].S.S);
		temp.pb(mp(xf,mp(y,z)));
	}
	b=temp;
	temp.clear();
}

int main()
{
	ll n,k;
	sl(n); sl(k);
	rep(i,0,n)
	sl(par[i]);
	rep(i,0,n)
	{
		sl(wt[i]);
		a.pb(mp(par[i],mp(wt[i],wt[i])));
	}
	foo(k,n);
	rep(i,0,n)
	printf("%lld %lld\n",b[i].S.F,b[i].S.S);
	return 0;
}