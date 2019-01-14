#include<bits/stdc++.h>

class KMP
{
	public:

	std::string pattern;
	std::vector< int > lps;

	KMP( const std::string &pat )
	{
		pattern = pat;
		lps = construct_LPS_array( pat );
	}

	// Constructs LPS array
	// LPS[i] is the longest proper prefix which is also a suffix for the 
	// substring pat[0...i]
	std::vector< int > construct_LPS_array( const std::string &pat )
	{
		std::vector< int > LPS( pat.length(), 0 );

		if( pat.empty() )	return LPS;

		int current_index = 0;
		for( int i = 1; i < pat.length() ; )
		{
			if( pat[ current_index ] == pat[ i ] )
			{
				current_index++;
				LPS[ i++ ] = current_index;
			}
			else
			{
				if( !current_index )
					LPS[ i++ ] = current_index;
				else
					current_index = LPS[ current_index-1 ];
			}
		}
		return LPS;
	}

	// Get starting index ( zero-based ) of all matches
	std::vector<int> get_matches( const std::string &text )
	{
		std::vector< int > matches;
		int pattern_index = 0;
		for( int text_index = 0; text_index < text.length(); )
		{
			if( pattern[ pattern_index ] == text[ text_index ] )
			{
				pattern_index++;
				text_index++;
			}
			else
			{
				if( pattern_index )
					pattern_index = lps[ pattern_index - 1 ];
				else
					text_index++;
			}

			// Found a match
			if( pattern_index == pattern.length() )
			{
				matches.push_back( text_index - pattern_index );
				pattern_index = lps[ pattern_index - 1 ];
			}
		}
	}

};

int main()
{
	std::string str;
	std::cin >> str;
	KMP x(str);
	std::vector< int > v = x.get_matches( "abab" );
	for( int i=0;i<v.size();i++ )
		printf("%d ",v[i] );
	printf("\n");
}