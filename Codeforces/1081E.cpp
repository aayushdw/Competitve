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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 200000
using namespace std;

ll square[MAX];
ll a[MAX];

ll squareRoot( ll x )
{
	ll s = ( (long long int) (sqrt(x)) );
	rep(i,s-2,s+2)
		if(i*i==x)
			return i;

	return -1;
}

bool foo( ll idx, ll size, ll sq )
{
	if(idx >= size )
		return true;

	if( a[idx] != -1 )
	{
		if( squareRoot( sq*sq + a[idx] ) == -1 )
			return false;
		else
			return foo( idx+1, size, squareRoot( sq*sq + a[idx] ) );
	}
	else
	{
		rep(i,sq+1,MAX)
		{
			a[idx] = i*i - sq*sq;
			if( foo( idx+1, size, i ) )
				return true;
			a[idx] = -1;
		}
		return false;
	}
}

int main()
{
	rep(i,0,MAX)
		square[i] = i*i;
	ll n;
	sl(n);

	memset(a,-1,sizeof(a));
	rep(i,0,n/2)
		sl(a[2*i+1]);

	rep(i,1,MAX)
	{
		a[0] = i*i;
		if( foo(1,n,i) )
		{
			printf("Yes\n");
			rep(j,0,n)
				printf("%lld ", a[j]);
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}