#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
vector<pair< ii,ii > > v;
void horizontal(int a,int b)
{
	v.pb(mp(mp(a+1,b+2),mp(a+1,b+3)));
	v.pb(mp(mp(a+1,b+3),mp(a+1,b+4)));
	v.pb(mp(mp(a+1,b+2),mp(a+1,b+3)));
	v.pb(mp(mp(a+1,b+1),mp(a+1,b+2)));
	v.pb(mp(mp(a+1,b+3),mp(a+1,b+4)));
}
void vertical(int a,int b)
{
	v.pb(mp(mp(a+2,b+1),mp(a+3,b+1)));
	v.pb(mp(mp(a+3,b+1),mp(a+4,b+1)));
	v.pb(mp(mp(a+2,b+1),mp(a+3,b+1)));
	v.pb(mp(mp(a+1,b+1),mp(a+2,b+1)));
	v.pb(mp(mp(a+3,b+1),mp(a+4,b+1)));
}
void v5(int a,int b)
{
	v.pb(mp(mp(a+4,b+1),mp(a+5,b+1)));
	v.pb(mp(mp(a+3,b+1),mp(a+4,b+1)));
	vertical(a,b);
}
void h5(int a,int b)
{
	v.pb(mp(mp(a+1,b+4),mp(a+1,b+5)));
	v.pb(mp(mp(a+1,b+3),mp(a+1,b+4)));
	horizontal(a,b);
}

void solve(int a,int b,int n)
{
	int x=0,y=0;
	if(n==2)
	{
		v.pb(mp(mp(a+1,b+1),mp(a+2,b+1)));
		v.pb(mp(mp(a+1,b+2),mp(a+2,b+2)));
		v.pb(mp(mp(a+1,b+1),mp(a+1,b+2)));
		v.pb(mp(mp(a+2,b+1),mp(a+2,b+2)));
	}
	else if(n==4)
	{
		solve(a,b,2);
		solve(a+2,b,2);
		solve(a,b+2,2);
		solve(a+2,b+2,2);
		rep(i,0,4)
		horizontal(a+i,b);
		rep(i,0,4)
		vertical(a,b+i);
	}
	else if(n==5)
	{
		solve(a+1,b,4);
		h5(a+4,b);
		solve(a,b+1,4);
		solve(a,b,4);
		rep(i,0,4)
		h5(a+i,b);
		rep(i,0,5)
		v5(a,b+i);
	}
	else
	{
		solve(a,b,4);
		solve(a,b+3,n-3);
		solve(a+3,b,n-3);
		solve(a+3,b+3,n-3);
		rep(i,0,n)
		v.pb(mp(mp(a+i+1,b+3),mp(a+i+1,b+4)));
		rep(i,0,n)
			v.pb(mp(mp(a+3,b+i+1),mp(a+4,b+i+1)));
		rep(i,0,n)
			horizontal(a+i,b);
		rep(i,0,n)
			vertical(a,b+i);
	}
}
int main()
{
	int n;
	sc(n);
	solve(0,0,n);
	int x=v.size();
	pr(x);
	rep(i,0,v.size())
	printf("%d %d %d %d\n",v[i].F.F,v[i].F.S,v[i].S.F,v[i].S.S);
	return 0;
}