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
#define LIM 1000000000
#define MAX 300+5
using namespace std;

ll p[MAX][MAX];

int main()
{
	ll n,m;
	sl(n); sl(m);
	rep(i,0,n)
	rep(j,0,m)
	sl(p[i][j]);
	vl a(n,1);
	vl b(m,1);
	bool f=true;
	rep(i,0,n)
	rep(j,0,m)
	{
		a[i]*=p[i][j]/__gcd(p[i][j],a[i]);
		b[j]*=p[i][j]/__gcd(p[i][j],b[j]);
		if(a[i]>LIM || b[i] >LIM)
			f=false;
	}

	rep(i,0,n)
	rep(j,0,m)
	if(p[i][j]!=__gcd(a[i],b[j]))
		f=false;

	if(!f)
		pr(-1);
	else
	{
		rep(i,0,n)
		printf("%lld ",a[i]);
		printf("\n");
		rep(i,0,m)
		printf("%lld ",b[i]);
	}
	return 0;
}