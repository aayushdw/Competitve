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
#define MAX 300000+5
#define MAXN 3
using namespace std;

ll a[MAX],tree[4*MAX],lazy[4*MAX];
vi v[MAXN];

ll query(ll idx,ll l,ll r,ll q)
{
	if(q>r || q<l)
		return 0;
	if(l==r)
	{
		tree[idx]+=lazy[idx];
		lazy[idx]=0;
		return tree[idx];
	}
	ll m=(l+r)>>1;
	lazy[2*idx]+=lazy[idx];
	lazy[2*idx+1]+=lazy[idx];
	lazy[idx]=0;
	return query(2*idx,l,m,q)+query(2*idx+1,m+1,r,q);
}

void update(ll idx,ll l,ll r,ll ul,ll ur, ll d)
{
	if(ul>r || ur<l)
		return;
	if(ul<=l && r<=ur)
	{
		lazy[idx]+=d;
		return;
	}
	ll m=(l+r)>>1;
	update(2*idx,l,m,ul,ur,d);
	update(2*idx+1,m+1,r,ul,ur,d);
}

void pre()
{
	rep(i,1,MAXN/2)
		for(int j=i;j<=MAXN;j+=i)
			v[j].pb(i);
	rep(i,MAXN/2,MAXN)
		v[i].pb(i);
}

int main()
{
	pre();
	return 0;
	ll n,q,l,r,d,idx,p;
	sl(n);
	rep(i,1,n+1)
	sl(a[i]);
	clr(tree); clr(lazy);
	sl(q);
	while(q--)
	{
		sl(p);
		if(p-1)
		{
			sl(l); sl(r); sl(d);
			update(1,1,n,l,r,d);
		}
		else
		{
			sl(q);
			ll ans=0;
			rep(i,0,v[q].size())
			if(v[q][i]>n)
				break;
			else
				ans+=query(1,1,n,v[q][i]);
			prll(a[q]+ans);
		}
	}
	return 0;
}