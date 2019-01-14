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
#define pii pair<int,int> 
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
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 667
#define NUM 666
#define LOL 1000
using namespace std;



int row[LOL] = {0};
int col[LOL] = {0};
pii pos;
pii rook[MAX];
int _count = 0;

void scan( pii &x )
{
	cin >> x.F >> x.S;
	return;
}

pii foo()
{
	int up_left = 0, up_right = 0, down_left = 0, down_right = 0;
	rep( i,1,MAX )
	{
		if( rook[i].F < 500 and rook[i].S < 500 )
			up_left++;
		if( rook[i].F < 500 and rook[i].S > 500 )
			up_right++;
		if( rook[i].F > 500 and rook[i].S < 500 )
			down_left++;
		if( rook[i].F > 500 and rook[i].S > 500 )
			down_right++;
	}

	int min_quad = min( min( up_left, up_right ), min( down_right, down_left ) );

	if( min_quad == up_left )
		return mp( 1,1 );
	else if( min_quad == up_right )
		return mp( 1,-1 );
	else if( min_quad == down_left )
		return mp( -1,1 );
	else
		return mp( -1,-1 );
}

void lol( int x )
{
	rep(i,1,MAX)
		if( rook[i] == pos )
		{
			pos.F -= x;
			return;
		}
}

int bar( int x, int y )
{
	_count++;
	pos.F += x;
	pos.S += y;

	lol(x);

	printf( "%d %d\n", pos.F, pos.S );
	fflush( stdout );

	// if( row[pos.F] )
	// 	return 1;

	int idx;
	pii p;
	cin >> idx;
	scan( p );

	if( idx == -1 )
		return 1;

	if( !idx )
		return 1;

	row[ rook[idx].F ]--;
	col[ rook[idx].S ]--;

	rook[idx] = p;
	
	row[ rook[idx].F ]++;
	col[ rook[idx].S ]++;

	if( _count > 2000)
		return 1;

	return 0;
}

int main()
{
	scan( pos );

	rep(i,1,MAX)
	{
		scan( rook[i] );
		row[ rook[i].F ]++;
		col[ rook[i].S ]++;
	}

	// rep(i,1,MAX)
	// 	printf( "%d %d\n", rook[i].F, rook[i].S );

	while( pos.F > 500 )
		if( bar(-1,0) )
			return 0;

	while( pos.F < 500 )
		if( bar(1,0) ) 
			return 0;

	while( pos.S > 500 )
		if( bar(0,-1) )
			return 0;

	while( pos.S < 500 )
		if( bar(0,1) ) 
			return 0;

	pii x = foo();
	// pr(x);
	while(1)
		if( bar(x.F,x.S) )
			return 0;

	return 0;
}