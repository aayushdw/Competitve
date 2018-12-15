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
 
#define MOD 10000009
#define INF 4000000000000000000
using namespace std;

vl d(2*MOD+2,0);

int main()
{
	d[2] = 1;
	rep(i,3,2*MOD+2)
	{
		d[i] = (i-1)*(d[i-2]+d[i-1]);
		d[i] %= MOD;
		// prll(d[i]);
	}
	ll n,p,q,ans;
	sl(q);
	while(q--)
	{
		sl(n);
		if(n==1)
		{
			pr(0);
			continue;
		}
		p = (n-3)%(2*MOD);
		p = d[2+p];
		n %= MOD;
		n *= p;
		n %= MOD;
		prll(n);
		// fflush(stdout);
	}
	return 0;
}