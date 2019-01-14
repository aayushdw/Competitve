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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)    //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))       //set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000000000000000
#define INF 4000000000000000000
// #define MAX 1000000 + 1
// #define NUM 1234567890

#define MAX 1000000 + 1
#define NUM 1234567890

using namespace std;

#define MAXSIEVE 1000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 500 // sqrt(MAXSIEVE)/2
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

char a[MAXSIEVE/16+2];

void sieve()
{
	int i,j;
	memset( a, 255, sizeof(a) );
	a[0] = 0xFE;
	for(i = 1; i < MAXSQRT ; i++ )
		if( a[i>>3] & (1<<(i&7)) )
			for( j = i+i+i+1; j < MAXSIEVEHALF; j += i+i+1 )
			a[j>>3] &= ~(1<<(j&7));
	return;
}

vi prime_factors[MAX];
vi primes;

ll power_in_factorial( ll p, ll n )
{
	ll power = 0, curr = p;
	while( n / curr )
	{
		power += n / curr;
		curr *= p;
	}
	return power;
}

void pre()
{
	sieve();
	rep(i,2,MAX)
	{
		if( ( i%2 && isprime( i ) ) || i == 2 )
		{
			primes.pb( i );
			for( int j = i; j < MAX; j += i )
				prime_factors[j].pb( i );
		}
	}
}

bool check( ll prime, ll n, ll x )
{
	
	ll power_in_x = power_in_factorial( prime, x );
	if( power_in_factorial( prime, n ) < power_in_x * NUM )
		return false;
	return true;
}

ll binarySearch( ll prime, ll x )
{
	ll low = 1, high = MOD, mid;
	while( low + 1 < high )
	{
		mid = ( low + high ) >> 1;
		if( !check( prime, mid, x ) )
			low = mid+1;
		else
			high = mid;
	}

	if( check( prime, low, x ) )
		high = low;
	else
		low = high;

	return low;
}

ll solve( ll i )
{
	ll ret = 0;
	rep( j,0,prime_factors[i].size() )
		ret = max( ret, binarySearch( prime_factors[i][j] , i ) );
	return ret;
}

int main()
{
	pre();

	ll ans = 0;
	ll prev = 0;
	rep( i, 10, MAX )
	{
		prev = max( prev, solve( i ) );
		ans += prev;
		ans %= MOD;
		// printf( "%4lld %lld\n", i, solve( i ) );
	}

	prll( ans );

	return 0;
}