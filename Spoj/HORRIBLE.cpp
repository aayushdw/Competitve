#include <stdio.h>
#include <math.h>
#define MAX 270000
#define sc(x) scanf("%lld",&x)
#define ll long long int
ll tree[MAX] = {0};  // To store segment tree
ll lazy[MAX] = {0};  // To store pending updates

/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] += (se-ss+1)*diff;
        // same logic for checking leaf node or not
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    ll mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
 
    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
 

    /*si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        tree[si] += (se-ss+1)*lazy[si];
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
 
        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    if (ss>=qs && se<=qe)
        return tree[si];
        
    ll mid = (ss + se)/2;
    return (getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2));
}
 
// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
void constructSTUtil(ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = 0;
        lazy[si] = 0;
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    ll mid = (ss + se)/2;
    constructSTUtil(ss, mid, si*2+1);
    constructSTUtil(mid+1, se, si*2+2);
 
    tree[si] = (tree[si*2 + 1] + tree[si*2 + 2]);
    lazy[si] = (lazy[si*2 + 1] + lazy[si*2 + 2]);
}
 
void constructST(ll n)
{
    constructSTUtil(0, n-1, 0);
}
int main()
{
	ll t,n,c,type,p,q,v,i;
	sc(t);
	while(t--)
	{
		sc(n); sc(c);
		constructST(n);
		while(c--)
		{
			sc(type);
			if(!type)
			{
				sc(p); sc(q); sc(v);
				p--; q--;
				updateRange(n,p,q,v);
			}
			else
			{
				sc(p); sc(q);
				p--; q--;
				printf("%lld\n",getSum(n,p,q));
			}
		}
	}
    return 0;
}
