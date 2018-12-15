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

ll a[100005],tree[2][MAX];

ll query(ll k,ll prev,ll idx,ll start,ll end)
{
	if(start>end || prev>=k)
		return INT_MAX;
	//printf("%lld %lld %lld %lld\n",start,end,prev,k);
	if(start==end)
		return tree[1][idx]?start:INT_MAX;
	if(prev+tree[1][idx]<=k)
		return tree[0][idx];
	ll mid=(start+end)>>1;
	ll x=query(k,prev,2*idx+1,start,mid);
	ll y=query(k,prev+tree[1][2*idx+1],2*idx+2,mid+1,end);

	if(x==INT_MAX && y==INT_MAX)
		return x;
	else if(x==INT_MAX && y!=INT_MAX)
		return y;
	else if(y==INT_MAX)
		return x;
	else
		return (a[x]>=a[y])?x:y;
}

ll getSum(ll idx,ll start,ll end,ll i)
{
	//prll(idx);
	if(start>i)
		return 0;
	if(start==end)
		return tree[1][idx];
	if(end<=i)
		return tree[1][idx];
	ll mid=(start+end)>>1;
	return getSum(2*idx+1,start,mid,i)+getSum(2*idx+2,mid+1,end,i);
}

void update(ll idx,ll start,ll end,ll i)
{
	if(start>i || end<i)
		return;
	if(start==end)
	{
		a[start]=-1;
		tree[0][idx]=start;
		tree[1][idx]=0;
		return;
	}
	ll mid=(start+end)>>1;
	update(2*idx+1,start,mid,i);
	update(2*idx+2,mid+1,end,i);
	tree[0][idx]=( a[tree[0][2*idx+1]] >= a[tree[0][2*idx+2]] ) ? tree[0][2*idx+1] : tree[0][2*idx+2] ;
	//printf("tree: %lld %lld %lld\n",tree[0][idx],tree[0][2*idx+1],tree[0][2*idx+2]);
	tree[1][idx]=tree[1][2*idx+1]+tree[1][2*idx+2];
}

void build(ll idx,ll start,ll end)
{
	if(start==end)
	{
		tree[0][idx]=start;
		tree[1][idx]=1;
		return;
	}
	ll mid=(start+end)>>1;
	build(2*idx+1,start,mid);
	build(2*idx+2,mid+1,end);
	tree[0][idx]=(a[tree[0][2*idx+1]]>=a[tree[0][2*idx+2]])?tree[0][2*idx+1]:tree[0][2*idx+2];
	tree[1][idx]=tree[1][2*idx+1]+tree[1][2*idx+2];
}

int main()
{
	ll n,k;
	vl v;
	set<ll> s;
	sl(n); sl(k);
	rep(i,0,n)
	sl(a[i]);
	build(0,0,n-1);
	ll t=n;
	while(t--)
	{
		ll x=query(k+1,0,0,0,n-1);
		//printf("New Max=%lld\n",x);
		if(x<0 || x>n)
			break;
		s.insert(x);
		v.pb(a[x]);
		ll y=getSum(0,0,n-1,x);
		/*if(y==0)
			break;*/
		k-=(y-1);
		update(0,0,n-1,x);
		//printf("%lld %lld %lld\n",x,y,k);
		if(k<=0)
			break;
		/*rep(i,0,10)
		printf("%lld ",tree[0][i]);
		printf("\n");
		rep(i,0,10)
		printf("%lld ",tree[1][i]);
		printf("\n");*/
	}
	rep(i,0,n)
		if(s.find(i)==s.end())
			v.pb(a[i]);
	rep(i,0,v.size())
	printf("%lld ",v[i]);
	return 0;
}