#include<bits/stdc++.h>

struct Node
{
	int val;
	int count;
	int num_children;
	std::vector< Node* > child;

	Node( int Val, int Num_children )
	{
		val 		 = Val;
		count 		 = 1;
		num_children = Num_children;
		child.resize( num_children, nullptr );
	}
};

class Trie
{
	public:

		Node *root;
		int number_of_elements;
		int num_children;

		Trie( int Num_children )
		{
			root 			   = nullptr;
			number_of_elements = 0;
			num_children       = Num_children;
		}

		void insert( const std::vector< int > &v )
		{	insert( root, v, 0 );	}

	private:

		void insert( Node *_root, std::vector< int > &v, int idx )
		{
			if( idx >= v.size() )
				return;

			if( _root == nullptr )
				_root = new Node( v[ idx ], num_children );
			else
				_root.count++;

			insert( _root.children[ v[ idx ] ], v, idx+1 );
		}
};

int main()
{
	Node a(2,2);
	std::cout << a.val << std::endl;
	return 0;
}