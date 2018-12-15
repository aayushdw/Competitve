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
#define priority_queue pq;
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
#define MAX 400000+5
using namespace std;

int tree[MAX],lazy[MAX],a[MAX];
vector< pair< ii,int > > Q;

void update(int start, int end, int idx, int l, int r, int x)
{
	if(r<start || l>end)
		return;
	if(start==end)
	{
		tree[idx]+=x+lazy[idx];
		lazy[idx]=0;
		return;
	}
	if(start>=l && end<=r)
	{
		lazy[idx]+=x;
		return;
	}
	int mid = (start+end)/2;
	update(start,mid,2*idx+1,l,r,x);
	update(mid+1,end,2*idx+2,l,r,x);
	tree[idx]=max(tree[2*idx+1]+lazy[2*idx+1],tree[2*idx+2]+lazy[2*idx+2]);
}

int query(int start, int end, int idx, int l, int r)
{
	if(r<start || l>end)
		return 0;
	if(start==end)
		return tree[idx]+lazy[idx];
	if(start>=l && end<=r)
		return tree[idx]+lazy[idx];
	int mid = (start+end)/2;
	lazy[2*idx+1]+=lazy[idx];
	lazy[2*idx+2]+=lazy[idx];
	lazy[idx]=0;
	return max(query(start,mid,2*idx+1,l,r),query(mid+1,end,2*idx+2,l,r));
}

int main()
{
	int n,q,l,r,x;
	si(n); si(q);
	clr(tree);
	clr(lazy);
	rep(i,0,q)
	{
		si(l); si(r); si(x);
		Q.pb(mp(mp(l,r),x));
		update(0,n-1,0,l,r,x);
	}
	int ans=INT_MAX;
	rep(i,0,q)
	{
		l=Q[i].F.F;
		r=Q[i].F.S;
		x=Q[i].S;
		update(0,n-1,0,l,r,-x);
		ans=min(ans,query(0,n-1,0,0,n-1));
		update(0,n-1,0,l,r,x);
	}
	pr(ans);
	return 0;
}