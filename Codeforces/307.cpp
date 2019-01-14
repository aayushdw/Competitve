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
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 1000000+5
#define N 1000000
#define D 20000
using namespace std;

long double log_factorial[ MAX ] = {0};

void pre()
{
	rep( i, 2, MAX )
		log_factorial[ i ] = log_factorial[ i-1 ] + log10( i*( static_cast< long double >( 1 ) ) );
}

int main()
{
	pre();

	long double p = 0;

	for( int j = 0; 2*j <= D; j++ )
	{
		int i = D - 2*j;
		long double log_prob = ( log_factorial[ N ] + log_factorial[ D ] + log_factorial[ 2*j ] ) \
						- ( D * log10( N ) + log_factorial[ i ] + log_factorial[ j ] ) \
						- ( log_factorial[ N-i-j ] + log_factorial[ D-i ] )
						- j * log10( 2.0 );

		p += pow( 10, p );
	}

	printf( "%0.15Lf\n", p );

	return 0;
}