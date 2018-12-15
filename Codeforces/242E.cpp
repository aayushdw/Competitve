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
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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

ll arr[20][MAX],seg[20][MAX],lazy[20][MAX],a[MAX];

ll query(ll base[],ll tree[],ll lazy[],ll i,ll l,ll r,ll ql,ll qr)
{
	if(ql>r || qr<l)
		return 0;
	if(l>=ql && r<=qr)
	{
		if(lazy[i])
			return (r-l+1)-tree[i];
		else
			return tree[i];
	}
	ll m=(l+r)>>1;
	lazy[i<<1]^=lazy[i];
	lazy[(i<<1)|1]^=lazy[i];
	if(lazy[i])
	{
		tree[i]=(r-l+1)-tree[i];
		lazy[i]=0;
	}
	ll la=query(base,tree,lazy,i<<1,l,m,ql,qr);
	ll ra=query(base,tree,lazy,(i<<1)|1,m+1,r,ql,qr);
	return la+ra;
}

void update(ll base[],ll tree[],ll lazy[],ll i,ll l,ll r,ll ul,ll ur,ll val)
{
	if(ul>r || ur<l)
		return;
	if(l>=ul && r<=ur)
	{
		lazy[i]^=val;
		return;
	}
	ll m=(l+r)>>1;
	lazy[i<<1]^=lazy[i];
	lazy[(i<<1)|1]^=lazy[i];
	if(lazy[i])
	{
		tree[i]=(r-l+1)-tree[i];
		lazy[i]=0;
	}
	update(base,tree,lazy,i<<1,l,m,ul,ur,val);
	update(base,tree,lazy,(i<<1)|1,m+1,r,ul,ur,val);
	//tree[i]=tree[2*i+1]+tree[2*i+2];
	ll la = lazy[i<<1] ? (m-l+1)-tree[i<<1] : tree[i<<1];
	ll ra = lazy[(i<<1)|1] ? (r-m)-tree[(i<<1)|1] : tree[(i<<1)|1];
	tree[i]=la+ra;
}

void build(ll base[],ll tree[],ll lazy[],ll i,ll l,ll r)
{
	if(l==r)
	{
		tree[i]=base[l];
		lazy[i]=0;
		return;
	}
	ll m=(l+r)>>1;
	build(base,tree,lazy,i<<1,l,m);
	build(base,tree,lazy,(i<<1)|1,m+1,r);
	tree[i]=tree[i<<1]+tree[(i<<1)|1];
	lazy[i]=0;
}

int main()
{
	ll n,m,type,l,r,x;
	sl(n);
	rep(i,1,n+1)
	{
		sl(a[i]);
		rep(j,0,20)
		arr[j][i]=ison(a[i],j);
	}

	rep(i,0,20)
		build(arr[i],seg[i],lazy[i],1,1,n);
	
	sl(m);
	while(m--)
	{
		sl(type);
		if(type==1)
		{
			sl(l); sl(r);
			ll ans=0;
			rep(i,0,20)
			{
				ans+=query(arr[i],seg[i],lazy[i],1,1,n,l,r)*(1ll<<i);
				//cout<<query(arr[i],seg[i],lazy[i],0,1,n,l,r);
			}
			//cout<<endl;
			prll(ans);
		}
		else
		{
			sl(l); sl(r);
			sl(x);
			rep(i,0,20)
			if(ison(x,i))
			update(arr[i],seg[i],lazy[i],1,1,n,l,r,1);
		}
		
	}

	return 0;
}