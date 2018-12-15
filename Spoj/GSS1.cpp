#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define pll pair<ll,ll>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 100000000000ll
#define MAX 60000ll
#define LIM 4*MAX
using namespace std;
ll arr[MAX];
struct node
{ ll sum,msum,pre,suf; };
node tree[LIM];
node getSum(ll start, ll end, ll qs, ll qe, ll idx)
{
	node x,y,z;
	if(start>end || start>qe || end<qs)
	{
		x.sum=-INF;
		return x;
	}
	if(start>=qs && end<=qe)
	{
		//printf("Inside %lld %lld %lld %lld\n",start,end,qs,qe);
		x=tree[idx];
		return x;
	}
	else
	{
		//printf("Part %lld %lld %lld %lld\n",start,end,qs,qe);
		ll mid=(start+end)/2,a,b,c;
		y=getSum(start,mid,qs,qe,2*idx+1);
		z=getSum(mid+1,end,qs,qe,2*idx+2);
		if(y.sum==-INF)
			return z;
		if(z.sum==-INF)
			return y;
		x.sum=y.sum+z.sum;
		x.msum=max(y.msum,max(z.msum,y.suf+z.pre));
		x.pre=max(y.pre,y.sum+z.pre);
		x.suf=max(z.suf,z.sum+y.suf);
		return x;
	}
}
void buildTree(ll arr[], ll start, ll end, ll idx)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[idx].sum=tree[idx].msum=tree[idx].pre=tree[idx].suf=arr[start];
		return;
	}
	ll mid=(start+end)/2,a,b,c;
	buildTree(arr,start,mid,idx*2+1);
	buildTree(arr,mid+1,end,idx*2+2);
	tree[idx].sum=tree[2*idx+1].sum+tree[2*idx+2].sum;
	tree[idx].msum=max(tree[2*idx+1].msum,max(tree[2*idx+2].msum,tree[2*idx+1].suf+tree[2*idx+2].pre));
	tree[idx].pre=max(tree[2*idx+1].pre,tree[2*idx+1].sum+tree[2*idx+2].pre);
	tree[idx].suf=max(tree[2*idx+2].suf,tree[2*idx+2].sum+tree[2*idx+1].suf);
	return;
}
int main()
{
	ll n,m,x,y;
	node a;
	scll(n);
	rep(i,0,n)
	scll(arr[i]);
	buildTree(arr,0,n-1,0);
	scll(m);
	while(m--)
	{
		scll(x); scll(y);
		x--; y--;
		a=getSum(0,n-1,x,y,0);
		printf("%lld\n",a.msum);
	}
	return 0;
}