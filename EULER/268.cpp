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
// #define MAX 10000000000000000ll
#define MAX 2310ll
#define INF MAX+5
using namespace std;

ll primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

ll foo(ll p,ll x)
{
	ll mul = 1;
	ll c = 0;
	rep(i,0,25)
		if(ison(p,i))
		{
			// printf("%lld\n",i);
			mul = min(INF,mul*primes[i]);
			c++;
		}
	if(c<x)	mul = INF;
	if(c>=x && MAX/mul)
	{
		rep(i,0,25)
			if(ison(p,i))
				printf("[%lld] , ",primes[i]);
		printf("%lld %lld %lld\n",c,mul,MAX/mul);
	}
	int n = c-x+1;
	return pow(-1ll,c)*(MAX/mul);
}

int main()
{
	ll ans = 0;
	rep(i,0,1ll<<25)
		ans += foo(i,4);
	prll(ans);
	return 0;
}