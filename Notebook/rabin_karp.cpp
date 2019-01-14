#include<bits/stdc++.h>

class rabin_karp
{
	public:

	long long int base;
	long long int mod;
	long long int inv_base;
	long long int maxlen;
	std::vector< long long int > base_pow;
	std::vector< long long int > inv_base_pow;

	rabin_karp( long long int Base, long long int Mod, long long int Maxlen = 0 )
	{
		base = base;
		mod = Mod;
		maxlen = Maxlen;
		inv_base = modInv( base, mod );
		if( maxlen )
			precompute();
	}

	long long int modInv( long long int base, long long int mod )
	{	return powmod( base, mod-2, mod );	}

	// precompute base^i, invbase^i
	void precompute()
	{
		base_pow.resize( maxlen );
		inv_base_pow.resize( maxlen );

		base_pow[ 0 ] = inv_base_pow[ 0 ] = 1;
		for( int i = 1; i < maxlen; i++ )
		{
			base_pow[ i ] = ( base_pow[ i-1 ] * base ) % mod;
			inv_base_pow[ i ] = ( inv_base_pow[ i-1 ] * inv_base ) % mod;
		}
	}

	std::vector< long long int > get_prefix_hashes( const std::string &s )
	{
		std::vector< long long int > preHash( s.length() );

		if( s.empty() )	return preHash;

		preHash[0] = static_cast< long long int > ( s[0] ) % mod;

		// if precomputed base powers
		if( maxlen )
		{
			for( int i = 1; i < s.length(); i++ )
				preHash[ i ] = ( preHash[ i-1 ] + static_cast< long long int > ( s[ i ] ) * base_pow[ i ] ) %mod;
		}
		else
		{
			mul = 1;
			for( int i = 1; i < s.length(); i++ )
			{
				mul *= base;
				mul *= mod; 
				preHash[ i ] = ( preHash[i-1] + static_cast< long long int > ( s[ i ] ) * mul ) % mod;
			}
		}
		return preHash;
	}

	// get hash of substr s[i...j] given preHash vector
	long long int substr_hash( int i, int j, std::vector< long long int > preHash )
	{
		assert( j > i );
		assert( j < preHash.length() );

		if( !i )
			return preHash[ j ];
		else
			return substr_hash( i-1, preHash[ i-1 ], preHash[ j ] );
	}

	// get hash of a substring given hash before start and hash at end of substing
	// idx 		  -> index of substring start - 1 
	// hash_start -> preHash at idx
	// hash_end   -> preHash at end of substring
	long long int substr_hash( int idx, long long int hash_start, long long int hash_end )
	{
		long long int hash = preHash[ j ] - preHash[ i-1 ];

		if( maxlen )
			mul = inv_base_pow[ idx ];
		else
			mul = powmod( base, idx, mod );

		hash = ( hash * mul ) % mod;
		return hash;
	}
};

// base = 31 , mod = 10^9 + 7
// base = 163, mod = 10^9 + 9