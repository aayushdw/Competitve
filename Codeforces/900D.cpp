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
#define ii pair<int,in>t 
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
#define MAX 100000+5
using namespace std;

ll powmod(ll a,ll b)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x%MOD;
}

#define MAXSIEVE 100000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 500 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void seive()
{
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
	if (a[i>>3]&(1<<(i&7)))
	for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
	a[j>>3]&=~(1<<(j&7));
}

vl primes;
ll mobius(ll n)
{
	ll ret = 1;
	ll pf = 0;
	rep(i,0,primes.size())
	{
		ll p = primes[i];
		ll c = 0;
		while(n%p==0)
		{
			n/=p;
			c++;
		}
		if(c>1)
			ret = 0;
		pf+=c;
	}
	if(pf%2)
		ret*=-1;
	return ret;
}

int main()
{
	seive();
	primes.pb(2);
	for(ll i=3;i<MAXSIEVE;i+=2)
		if(isprime(i))
			primes.pb(i);
	ll x,y;
	sl(x); sl(y);
	if(y%x)
	{
		pr(0);
		return 0;
	}
	y/=x;
	if(y==1)
	{
		pr(1);
		return 0;
	}
	ll ans = powmod(2,y-1);
	ll i;
	for(i=2;i*i<y;i++)
	{
		if(y%i==0)
		{
			{
				ll mu = mobius(i);
				ll temp = mu*powmod(2,(y/i)-1);
				temp %= MOD;
				ans += temp;
				ans %= MOD;
			}
			{
				ll mu = mobius(y/i);
				ll temp = mu*powmod(2,i-1);
				temp %= MOD;
				ans += temp;
				ans %= MOD;
			}
		}

	}
	// if(i*i==y)
	// {
	// 	ll mu = mobius(i);
	// 	ll temp = mu*powmod(2,(y/i)-1);
	// 	temp %= MOD;
	// 	ans += temp;
	// 	ans %= MOD;
	// }
	// i = y;
	// {
	// 	ll mu = mobius(i);
	// 	ll temp = mu*powmod(2,(y/i)-1);
	// 	temp %= MOD;
	// 	ans += temp;
	// 	ans %= MOD;
	// }
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	prll(ans);
	return 0;
}