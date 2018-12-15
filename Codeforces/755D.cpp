#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 1000000+5
using namespace std;

ll getSum(ll BITree[], ll index)
{
    ll sum = 0; // Iniialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
ll *constructBITree(ll arr[], ll n)
{
    // Create and initialize BITree[] as 0
    ll *BITree = new ll[n+1];
    for (ll i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (ll i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
 
    return BITree;
}

ll base[MAX]={0};

int main()
{
	ll n,k,next,total=0;;
	sl(n); sl(k);
	ll m=n, curr=0, ans=1, sum,sum1;
	ll* a=constructBITree(base,n);
	while(m--)
	{
		next=curr+k;
		sum=1;
		sum-=getSum(a,curr);
		if(next<=n)
			sum+=getSum(a,next-1);
		else
		{
			sum+=getSum(a,n-1);
			sum+=getSum(a,next-n-1);
		}
		next%=n;
		sum1=total-base[curr]-base[next],sum;
		if(sum1>=0)
			sum=min(sum,sum1);
		ans+=sum;

		printf("%lld ",ans);
		updateBIT(a,n,curr,1);
		base[curr]++;
		updateBIT(a,n,next,1);
		base[next]++;
		total+=2;
		curr=next;
	}
	return 0;
}