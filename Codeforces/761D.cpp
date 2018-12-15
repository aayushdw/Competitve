#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
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
#define MAX 100000+5
using namespace std;

ll a[MAX],b[MAX],c[MAX];
vii v;


int main()
{
	ll n,l,r;
	sl(n); sl(l); sl(r);
	rep(i,0,n)
	sl(a[i]);
	rep(i,0,n)
	{
		sl(c[i]);
		v.pb(mp(c[i],i));
	}
	sort(v.rbegin(),v.rend());
	bool f=true;
	ll curr=r-a[v[0].S],x;
	rep(i,0,n)
	{
		x=v[i].S;
		b[x]=a[x]+curr;
		if(b[x]<l)
			f=false;
		if(b[x]>r)
			b[x]=r;
		curr=b[x]-a[x];
		curr--;
	}
	if(!f)
	{
		printf("-1");
		return 0;
	}
	rep(i,0,n)
	printf("%lld ",b[i]);
	return 0;
}