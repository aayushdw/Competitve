#include <bits/stdc++.h>
 
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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 1000000ll
#define MAX 17
using namespace std;

ll a[MAX];
bitset<INF> t;

ll solve(vl &contain)
{
	if(contain.size()==1)
		return 1ll*contain[0]*contain[0];
	
	vl halved(contain.size()/2);
	for(int i=0;i<contain.size()/2;i++)
		halved[i]=contain[i+contain.size()/2];
	ll ans = -solve(halved);
	
	for(int i=0;i<contain.size()/2;i++)
		halved[i]+=contain[i];
	ans+=solve(halved);
	
	return ans;
}

ll foo( ll p, ll q, ll n )
{
	ll ret = 0;
	rep(i,0,n)
		if(ison(p,i) && ison(q,i))
			return INF-1;
		else if( ! (ison(p,i) || ison(q,i) ) )
			ret += 1<<i;

	return ret;
}

int main()
{
	ll n, sum = 0;
	sl(n);

	rep(i,0,n)
	{
		sl(a[i]);
		sum += a[i];
	}

	if(sum%3)
	{
		pr(0);
		return 0;
	}

	vl v;
	rep(i,1,1ll<<n)
	{
		ll curr = 0;
		rep(j,0,n)
			curr += ison(i,j) * a[j];
		if( curr == sum/3 )
			v.pb(i);
	}

	/*t.reset();
	rep(i,0,v.size())
	{
		t[v[i]] = true;
		printf("%lld ",v[i]);
	}

	printf("\n");
	//pr(v.size());
	ll ans = 0;
	rep(i,0,v.size())
		rep(j,i+1,v.size())
			if( t[foo(v[i],v[j],n)] )
				ans++;*/

	vl contain(1ll<<MAX,0);
	rep(i,0,v.size())
		contain[v[i]]++;
	if(!sum)
		prll(solve(contain)-v.size()+1);
	else
		prll(solve(contain));
	// prll(ans*2);
	return 0;
}