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

int tree[6][4*MAX],a[MAX];

void build(int idx, int start, int end)
{
	if(start==end)
	{
		tree[0][idx] = a[idx];
		tree[1][idx] = 1;
		tree[2][idx] = a[idx];
		tree[3][idx] = 1;
		tree[4][idx] = a[idx];
		tree[5][idx] = 1;
	}
	
	int mid = (start+end)>>1;
	build(2*idx+1,start,mid);
	build(2*idx+2,mid+1,end);

	if(tree[0][2*idx+1]>tree[0][2*idx+2])
	{
		tree[0][idx] = tree[0][2*idx+1];
		tree[1][idx] = tree[1][2*idx+1];
	}

	if(tree[0][2*idx+1]<tree[0][2*idx+2])
	{
		tree[0][idx] = tree[0][2*idx+2];
		tree[1][idx] = tree[1][2*idx+2];
	}

	if(tree[4][2*idx+1]==tree[2][2*idx+2] && tree[5][2*idx+1]+tree[3][2*idx+2]>tree[0][idx])
	{
		tree[0][idx] = tree[5][2*idx+1]+tree[3][2*idx+2];
		tree[1][idx] = tree[4][2*idx+1];
	}

	tree[2][idx] = tree[2][2*idx+1];
	tree[3][idx] = tree[3][2*idx+1];
	tree[4][idx] = tree[4][2*idx+2];
	tree[5][idx] = tree[5][2*idx+2];

	if(mid-start+1==tree[3][2*idx+1] && tree[2][2*idx+1]==tree[2][2*idx+2])
		tree[2][idx] = tree[2][2*idx+1] + tree[2][2*idx+2];
	if(end-mid==tree[5][2*idx+2] && tree[5][2*idx+1]==tree[5][2*idx+2])
		tree[5][idx] = tree[5][2*idx+1] + tree[5][2*idx+2];
	return;
}

int main()
{
	int n,m;
	si(n); si(m);
	rep(i,0,n)
		si(a[i]);
	build();
	while(m--)
	{
		si(l); si(r);
		if()
			pr();
		else
			pr(-1);
	}
	return 0;
}