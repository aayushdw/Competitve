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
#define MAX 3000
#define CHECK 60
using namespace std;

vi rifleShuffle( vi v )
{
	vi first( v.begin(), v.begin() + v.size()/2 );
	vi second( v.begin() + v.size()/2, v.end() );

	vi ret;
	rep(i,0,v.size()/2)
	{
		ret.pb( first[i] );
		ret.pb( second[i] );
	}
	return ret;
}

void print( const vi &v )
{
	rep(i,0,v.size())
		printf("%2d ",v[i]);
	printf("\n");
}

int check( int n )
{
	vi v(n),orig(n);
	rep(i,0,n)
	{
		v[i] = i;
		orig[i] = i;
	}
	print(v);
	rep(i,1,1000)
	{
		v = rifleShuffle(v);
		print(v);
		// if( v[n/2] ==1 )
		// 	pr(i+1);
		if( v == orig )
			return i;
	}
	return -1;
}

int main()
{
	int n;
	si(n);
	check( n );
	// ll ans = 0;
	// for( int i = 2; i < MAX ; i+=2 )
	// {
	// 	int x = check(i);
	// 	if( x > 0 )
	// 		printf("%5d %4d\n", i,x );
	// 	if( x == CHECK )
	// 		ans += i;
	// }
	// prll(ans);
	return 0;
}