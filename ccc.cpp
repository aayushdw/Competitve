#include <bits/stdc++.h> 
#define ll long long
#define FLAG 100000000000000ll
using namespace std;

ll GetSum( vector< ll > &v )
{
	ll ret = 0;
	for( ll i=1 ; i < v.size() ; i++ )
		if( v[i] != FLAG && v[i-1] != FLAG )
			ret += abs( v[i] - v[i-1] );
	return ret;
}

int main()
{
	ll n;
	scanf( "%lld", &n );
	vector< ll > a(n+2);
	for( ll i = 1 ; i <= n ; i++ )
		scanf( "%lld", &a[i] );
	a[0] = 0;
	a[n+1] = FLAG;

	ll current = GetSum(a);
	ll ans = current;
	
	vector< ll > v1, v2;
	for( ll i = 1 ; i <= n ; i++)
	{
		for( ll j = i+1 ; j <=n ; j++ )
		{
			v1.clear();
			v2.clear();
			ll temp;
			if( i == j-1 )
			{
				for( ll k = i-1; k <= j+1 ; k++ )
					v1.push_back( a[k] );
				temp = GetSum( v1 );
				swap( v1[1], v1[2] );
				temp -= GetSum( v1 );
			}
			else
			{
				for( ll k = i-1; k<= i+1 ; k++ )
					v1.push_back( a[k] );
				for( ll k = j-1; k<= j+1 ; k++ )
					v2.push_back( a[k] );

				temp = GetSum( v1 ) + GetSum( v2 );
				swap( v1[1], v2[1] );
				temp -= GetSum( v1 ) + GetSum( v2 );
			}
			ans = min( ans, current-temp );
		}
	}
	printf( "%lld\n", ans );
	return 0;
}