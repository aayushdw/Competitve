#include<bits/stdc++.h>
 
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
#define INF 4000000000000000000
#define MAX 4000+5
using namespace std;

ll row[MAX]={0},col[MAX]={0},TreeRow[MAX],TreeCol[MAX],RowStore[MAX],ColStore[MAX],lazyRow=0,lazyCol=0;

void update(ll a[],ll tree[],ll store[],ll idx,ll start, ll end,ll u, ll val)
{
	if(start>u || end<u)
		return;
	if(start==end)
	{
		a[start]=val;
		tree[idx]=a[start];
		store[idx]=start;
		return;
	}
	ll mid=(start+end)>>1;
	update(a,tree,store,2*idx+1,start,mid,u,val);
	update(a,tree,store,2*idx+2,mid+1,end,u,val);
	tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
	store[idx]=(tree[2*idx+1]>tree[2*idx+2]) ? store[2*idx+1] : store[2*idx+2];
}

void buildTree(ll a[],ll tree[],ll store[],ll idx, ll start,ll end)
{
	if(start==end)
	{
		tree[idx]=a[start];
		store[idx]=start;
		return;
	}
	ll mid=(start+end)>>1;
	buildTree(a,tree,store,2*idx+1,start,mid);
	buildTree(a,tree,store,2*idx+2,mid+1,end);
	tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
	store[idx]=(tree[2*idx+1]>tree[2*idx+2]) ? store[2*idx+1] : store[2*idx+2];
}

int main()
{	
	ll n,m,k,p,temp;
	sl(n); sl(m); sl(k); sl(p);
	rep(i,0,n)
	rep(j,0,m)
	{
		sl(temp);
		row[i]+=temp;
		col[j]+=temp;
	}
	buildTree(row,TreeRow,RowStore,0,0,n-1);
	buildTree(col,TreeCol,ColStore,0,0,m-1);
	ll ans=0;
	printf("\n");
	while(k--)
	{
		ll x=TreeRow[0]-lazyRow*p,y=TreeCol[0]-lazyCol*p;
		printf("%lld %lld\n",x,y);
		if(x>y)
		{
			ans+=TreeRow[0]-lazyRow*p;
			update(row,TreeRow,RowStore,0,0,n-1,RowStore[0],row[RowStore[0]]-m*p);
			lazyCol++;
		}
		else
		{
			ans+=TreeCol[0]-lazyCol*p;
			update(col,TreeCol,ColStore,0,0,m-1,ColStore[0],col[ColStore[0]]-n*p);
			lazyRow++;
		}
		prll(ans);
	}
	prll(ans);
	return 0;
}