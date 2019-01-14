class weightedDirectedGraph
{
	private:
		const int UNMARKED 	= 0;
		const int TEMP_MARK = 1;
		const int PERM_MARK = 2;

	public:
		// 1-based indexing
		int num_nodes;	// number of nodes
		int num_edges; 	// number of edges
		vector< vector< ii > > adj; // adjacaency matrix 

		// pass number of nodes
		weightedDirectedGraph( int n )
		{
			num_nodes = n;
			num_edges = 0;
			adj.resize( num_nodes + 1 );
		}

		void add_edge( int u, int v, int w )
		{
			adj[u].push_back( make_pair( v, w ) );	// edge from u to v of weight w
			num_edges ++;
		}

		inline int to( ii p )		{	return p.first;		}

		inline int weight( ii p )	{	return p.second;	}

		bool toposort_dfs( vi &vec, vi &vis, int u )
		{
				 if( vis[u] == PERM_MARK )	return true;
			else if( vis[u] == TEMP_MARK )	return false;

			vis[ u ] = TEMP_MARK;

			bool ret = true;
			for( auto v: adj[u] )
				ret |= toposort_dfs( vec, vis, to( v ) );

			vis[ u ] = PERM_MARK;
			vec.push_back( u );
			return ret;
		}

		// return a possible toposort
		// return empty array if cyclic
		vi toposort()
		{
			vi vis( num_nodes + 1, UNMARKED );

			// reversed toposorted array
			vi ret;

			rep( i, 1, num_nodes + 1 )
				if( !vis[i] )
					// detected a cycle
					if( !toposort_dfs( ret, vis, i ) )
					{
						ret.resize( 0 );
						return ret;
					}

			reverse( all( ret ) );
			assert( num_nodes == ret.size() );
			return ret;
		}
};