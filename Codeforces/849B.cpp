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
#define ii pair<ll,ll> 
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
#define MAX 1000+5
using namespace std;

ll y[MAX],n;
vector< ii > v;
bitset<MAX> vis;

bool check(ii x, ii y, ii z)
{
	ii p = mp(y.S-x.S,y.F-x.F);
	ii q = mp(z.S-x.S,z.F-x.F);
	//printf("(%lld %lld) (%lld %lld) (%lld %lld) %d\n",x.F,x.S,y.F,y.S,z.F,z.S,p.F*q.S == p.S*q.F);
	return p.F*q.S == p.S*q.F;
}

bool isParallel(ii a, ii b, ii c, ii d)
{
	ii p = mp(a.S-b.S,a.F-b.F);
	ii q = mp(c.S-d.S,c.F-d.F);
	return p.F*q.S == p.S*q.F;
}

bool CHECK(ll a,ll b)
{
	//cout<<endl<<endl;
	vl x;
	ll p = 0;
	rep(i,0,n)
	{
		bool f = check(v[a],v[b],v[i]);
		p+=f;
		if(!f)
			x.pb(i);
	}
	//prll(p);
	if(p==n-1)
		return true;
	else if(p==n)
		return false;
	if(!isParallel(v[a],v[b],v[x[0]],v[x[1]]))
		return false;
	//cout<<endl;
	ll c=0;
	rep(i,0,n)
		c+=check(v[x[0]],v[x[1]],v[i]);
		//printf("%lld %lld\n",p,c);
	if(p+c==n)
		return true;
	return false;
}

int main()
{
	sl(n);
	rep(i,0,n)
	{
		sl(y[i]);
		v.pb(mp(i,y[i]));
	}

	rep(i,1,n)
	if(CHECK(0,i))
	{
		//cout<<0<<" "<<i<<endl;
		printf("Yes");
		return 0;
	}

	rep(i,2,n)
	if(CHECK(1,i))
	{
		//cout<<1<<" "<<i<<endl;
		printf("Yes");
		return 0;
	}

	printf("No");
	return 0;
}