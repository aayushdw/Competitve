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
#define MAX 100005ll
#define LIM 4*MAX
using namespace std;
struct node { ll sum; set<int> v; };
ll arr[MAX];
node tree[LIM];
node getSum(ll start, ll end, ll qs, ll qe, ll idx)
{
	node x,y,z; x.sum=0; x.v.clear();
	if(start>end || start>qe || end<qs)
		return x;
	if(start>=qs && end<=qe)
		return x=tree[idx];
	else
	{
		ll mid=(start+end)/2;
		y=getSum(start,mid,qs,qe,2*idx+1);
		z=getSum(mid+1,end,qs,qe,2*idx+2);
		//printf("%lld %lld\n",y.sum,z.sum);
		if(y.sum==0)
			return z;
		if(z.sum==0)
			return y;
		typeof(x.v.begin()) it;
		for(it=y.v.begin();it!=y.v.end();it++)
		{
			x.v.insert(*it); //printf("y%d ",*it);
		}
		for(it=z.v.begin();it!=z.v.end();it++)
		{
			x.v.insert(*it); //printf("z%d ",*it);
		}
		for(it=x.v.begin();it!=x.v.end();it++)
			x.sum+=*it;
		return x;
	}
}
void buildTree(ll arr[], ll start, ll end, ll idx)
{
	if(start>end)
		return;
	if(start==end)
	{
		if(arr[start]<=0)
			return;
		tree[idx].sum=arr[start];
		tree[idx].v.insert(arr[start]);
		return;
	}
	ll mid=(start+end)/2;
	buildTree(arr,start,mid,2*idx+1);
	buildTree(arr,mid+1,end,2*idx+2);
	typeof(tree[idx].v.begin()) it;
	for(it=tree[2*idx+1].v.begin();it!=tree[2*idx+1].v.end();it++)
		tree[idx].v.insert(*it);
	for(it=tree[2*idx+2].v.begin();it!=tree[2*idx+2].v.end();it++)
		tree[idx].v.insert(*it);
	tree[idx].sum=0;
	for(it=tree[idx].v.begin();it!=tree[idx].v.end();it++)
		tree[idx].sum+=*it;
	return;
}
int main()
{
	ll n,m,x,y;
	node p;
	typeof(p.v.begin()) it;
	scll(n);
	rep(i,0,n)
	scll(arr[i]);
	buildTree(arr,0,n-1,0);
	/*rep(i,0,15)
	{
		printf("sum=%lld Elements: ",tree[i].sum);
		for(it=tree[i].v.begin();it!=tree[i].v.end();it++)
			printf("%d ",*it);
		printf("\n");
	}*/
	scll(m);
	while(m--)
	{
		scll(x); scll(y);
		x--; y--;
		p=getSum(0,n-1,x,y,0);
		printf("%lld\n",p.sum);
	}
	return 0;
}