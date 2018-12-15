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
#define MAX 30
using namespace std;

ll k,a[MAX],ans=0;
vl v[2];

void foo(ll i,ll p,vl& q,ll n)
{
	if(i==n)
		return;
	foo(i+1,p,q,n);
	long double x=p*1.0,y=a[i]*1.0,z=k*1.0;
	if(x*y>=z)
		return;
	p*=a[i];
	if(p<=k)
	{
		ans++;
		q.pb(p);
		foo(i+1,p,q,n);
	}
}

ll bin_search(vl& x,ll key)
{
	ll low=0,high=(ll)x.size()-1,mid;
	if(x[low]>key)
		return 0;
	if(x[high]<key)
		return high+1;
	while(low!=high)
	{
		if(low+1==high)
		{
			if(x[high]<=key)
				return high+1;
			return low+1;
		}
		//prll(low);
		//prll(high);
		mid=(low+high+1)>>1;
		if(x[mid]>key)
			high=mid;
		else
			low=mid;
	}
	return low+1;
}

int main()
{
	ll n;
	sl(n); sl(k);
	rep(i,0,n)
	sl(a[i]);
	foo(0,1,v[0],n/2);
	foo(n/2,1,v[1],n);

	/*rep(i,0,v[0].size())
	printf("%lld ",v[0][i]);
	printf("\n");
	rep(i,0,v[1].size())
	printf("%lld ",v[1][i]);
	printf("\n");*/

	sort(all(v[0]));
	sort(all(v[1]));

	rep(i,0,v[0].size())
	ans+=bin_search(v[1],k/v[0][i]);
	prll(ans);
}