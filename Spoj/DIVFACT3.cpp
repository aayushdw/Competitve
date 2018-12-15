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
#define MAX 110000000
using namespace std;

ll pi[MAX];

#define MAXSIEVE 110000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5500 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void sieve()
{
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
	if (a[i>>3]&(1<<(i&7)))
	for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
	a[j>>3]&=~(1<<(j&7));
}

ll expPrimeFact(ll n,ll p,ll m)
{
	ll ret=0,x,q=p;
	bool f=false;
	while(1)
	{
		x=n/q;
		ret+=x;
		ret%=m;
		q*=p;
		if(q>n)
			break;
	}
	return ret;
}

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    if(a==0)
    	return 0;
    if(b<=0)
    	return 1;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

int main()
{
	sieve();
	clr(pi);
	pi[2]=1;
	rep(i,3,MAX)
	if(i%2)
		pi[i]=pi[i-1]+(isprime(i)!=0);
	else
		pi[i]=pi[i-1];

	vl primes;
	primes.pb(2);
	for(ll i=3; i*i<MAX; i+=2)
		if(isprime(i))
			primes.pb(i);

	ll t,n,m;
	ll ans;
	sl(t);
	while(t--)
	{
		sl(n);
		sl(m);
		
		ans=1;
		ll i=0;
		while(primes[i]*primes[i]<=n)
		{
			//pr(primes[i]);
			ans*=expPrimeFact(n,primes[i],m)+1;
			//prll(expPrimeFact(n,primes[i]));
			ans%=m;
			i++;
		}
		//prll(ans);
		ll l,r;
		rep(j,1,n)
		{
			l=n/(j+1)+1; r=n/j;
			if(l*l<=n)
				break;
			ans*=powmod(j+1,pi[r]-pi[l-1],m);
			//printf("%d %d %d %lld\n",l,r,pi[r]-pi[l-1],powmod(j+1,pi[r]-pi[l-1],m));
			ans%=m;
		}
		prll(ans);	
	}
	return 0;
}