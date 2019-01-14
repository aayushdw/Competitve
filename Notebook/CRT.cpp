class CRT
{
	public:
		typedef long long int ll;

		ll multi( ll x, ll y, ll mod )
		{
			ll w= x * y - mod * ( (ll)( double(x) * y / mod + 1e-3 ) );
			while(w<0)
				w+=mod;
			while(w>=mod)
				w-=mod;
			return w;
		}

		pair< ll, ll > extendedGCD( ll a, ll b )
		{
			if( !a )
				return make_pair( 0, 1 );

			pair< ll, ll > ret = extendedGCD( b % a, a );
			ret.first = ret.second - ( b / a ) * ret.first;
			swap( ret.first, ret.second );
			return ret;
		}

		ll lcm( ll a, ll b )
		{	return a * ( b / gcd( a, b ) );	}

		pair< ll, ll > crt_coprime_moduli( pair< ll, ll > x, pair< ll, ll > y )
		{
			
			period = x.second * y.second;
			pair< ll, ll > exGCD = extendedGCD( x.first, y.first );

			solution = 	( ( ( y.first * exGCD.first ) % period ) * x.second ) % period + \
						( ( ( x.first * exGCD.second ) % period ) * y.second ) % period

			solution %= period;

			return make_pair( solution, period );
		}

		pair< ll, ll > crt_general( pair< ll, ll > x, pair< ll, ll > y )
		{
			// gcd of moduli must divide difference of residue to have a solution
			if( abs( x.first - y.first ) % __gcd( x.second, y.second ) )
				return make_pair( -1, -1 );

			period = lcm( x.second, y.second );
			pair< ll, ll > exGCD = extendedGCD( x.first, y.first )

			solution = x.first + multi( multi( exGCD.first, ( x.first - y.first ) / d, period ), x.second, period );
		}

		pair< ll, ll > get_unique_solution( pair< ll, ll > x, pair< ll, ll > y )
		{
			if( __gcd( x.second, y.second ) == 1 )
				return crt_coprime_moduli( x, y );
			else
			{
				// IMPLEMENT FOR NON COPRIME MODULI
			}
		}
};