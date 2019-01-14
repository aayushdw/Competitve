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
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

class weightedDirectedGraph
{
	private:
		const int UNMARKED 	= 0;
		const int TEMP_MARK = 1;
		const int PERM_MARK = 2;

	public:
		int indexing;
		int num_nodes;	// number of nodes
		int num_edges; 	// number of edges
		vector< vector< ii > > adj; // adjacaency matrix 

		// pass number of nodes and indexing style ( 0-based or 1-based )
		weightedDirectedGraph( int n, int index = 1 )
		{
			assert( ( index == 0 || index == 1 ) && n >= 0 );
			indexing  = index;
			num_nodes = n;
			num_edges = 0;
			adj.resize( num_nodes + indexing );
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
			vi vis( num_nodes + indexing, UNMARKED );

			// reversed toposorted array
			vi ret;

			rep( i, indexing, num_nodes + indexing )
				if( !vis[i] )
					// detected a cycle
					if( !toposort_dfs( ret, vis, i ) )
					{
						ret.resize( 0 );
						return ret;
					}

			reverse( all( ret ) );
			return ret;
		}

		bool is_cyclic()
		{	return ( toposort().size() == num_edges ); 	}
};

void print( vi &v, int n = -1 )
{
	if( n < 0 )	n = v.size();
	rep( i, 0, n )
		printf("%d ", v[i]);
	printf( "\n" );
}

void include_small_edges( weightedDirectedGraph &G, weightedDirectedGraph &Graph, int max_weight )
{
	for( int i = Graph.indexing; i < Graph.num_nodes + Graph.indexing; i++ )
		for( auto v: Graph.adj[i] )
			if( Graph.weight(v) <= max_weight )
				G.add_edge( i, Graph.to( v ), Graph.weight( v ) );
}

vector< ii > large_edges_list( weightedDirectedGraph &Graph, int max_weight )
{
	vector< ii > ret;
	for( int i = Graph.indexing; i < Graph.num_nodes + Graph.indexing; i++ )
		for( auto v: Graph.adj[i] )
			if( Graph.weight(v) > max_weight )
				ret.pb( mp( i, Graph.to( v ) ) );

	return ret;
}

bool has_cycle( int max_weight, weightedDirectedGraph  &Graph )
{
	weightedDirectedGraph G( Graph.num_edges, Graph.indexing );
	include_small_edges( G, Graph, max_weight );
	return G.is_cyclic();
}

int main()
{
	int n,m;
	cin >> n >> m;

	weightedDirectedGraph G(n);
	while( m-- )
	{
		int u, v, w;
		cin >> u >> v >> w;
		G.add_edge( u, v, w );
	}

	int low = 0, high = MOD;

	while( low + 1 < high )
	{
		int mid = ( low + high ) >> 1;
		if( has_cycle( mid, G ) )
			high = mid - 1;
		else
			low = mid;
	}
	if( has_cycle( low, G ) )	high = low;
	else low = high;
	
	weightedDirectedGraph Graph( G.num_edges, G.indexing );
	include_small_edges( Graph, G ,low );
	vector< ii > edge_list = large_edges_list( G, low );

	vi toposort = G.toposort();

	vi v( G.num_edges + G.indexing );
	rep( i, 0, toposort.size() )
		v[ toposort[i] ] = i;

	vii ans;
	rep( i, 0, edge_list.size() )
	{
		if( v[ edge_list[i].F ]  v[ edge_list[i].F ] )
			ans.pb( edge_list(i) );
	}

	return 0;
}