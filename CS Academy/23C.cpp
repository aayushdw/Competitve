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
#define MAX 100000+5
using namespace std;

ll n,m;
ll par[MAX],sum[MAX],len[MAX],ans[MAX],a[MAX];


void dfs(ll i)
{
	vl v;
	v.pb(a[i]);
	ll p=i;
	sum[i]=i;
	len[i]=1;
	p=a[p];
	while(p!=i)
	{
		v.pb(a[p]);
		//prll(p);
		len[i]++;
		par[p]=i;
		sum[i]+=p;
		p=a[p];
	}
	//printf("%lld %lld %lld\n",i,len[i],sum[i]);
	/*rep(j,0,v.size())
	printf("%lld ",v[j]);
	printf("\n");*/

	rep(j,0,v.size())
	ans[v[j]]=(m/len[i])*sum[i];
	ll mm=m%len[i];

	ll x=0;
	rep(j,0,mm)
	x+=v[j];

	//prll(x);

	ans[i]+=x;
	rep(j,1,v.size())
	{
		x-=v[j-1];
		x+=v[(mm+j-1)%len[i]];
		ans[v[j-1]]+=x;
	}
}

int main()
{
	sl(n); sl(m);
	rep(i,1,n+1)
	sl(a[i]);

	rep(i,1,n+1)
	par[i]=i, sum[i]=0;

	rep(i,1,n+1)
	if(i==par[i])
		dfs(i);

	rep(i,1,n+1)
	printf("%lld ",ans[i]);

	return 0;
}