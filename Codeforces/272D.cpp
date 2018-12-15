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
#define INF 4000000000000000000
#define MAX 200000+5
using namespace std;

ll f[MAX];

void pre(ll m)
{
	f[0] = 1;
	rep(i,1,MAX)
	{
		ll j = i;
		while(j%2==0)
			j/=2;
		f[i] = f[i-1]*j;
		f[i] %= m;
	}
}

ll getPow2(ll n)
{
	ll ret = 0, p = 2;
	while(n/p)
	{
		ret += n/p;
		p *= 2;
	}
	return ret;
}

ll powmod(ll a,ll b,ll m)
{
	ll x = 1 , y = a;
	while(b>0)
	{
		if(b%2)
			x = (x*y)%m;
		y = (y*y)%m;
		b/=2;
	}
	return x%m;
}

int main()
{
	ll n,c=0,m;
	sl(n);
	vl v(2*n,0);
	rep(i,0,n)
		sl(v[i]);
	rep(i,n,2*n)
	{
		sl(v[i]);
		if(v[i]==v[i-n])
			c--;
	}
	sl(m);
	pre(m);
	sort(all(v));
	v.pb(-1);
	ll cur = 1;
	ll ans = 1;
	rep(i,1,v.size())
	{
		if(v[i]==v[i-1])
			cur++;
		else
		{
			ans *= f[cur];
			ans %= m;
			c += getPow2(cur);
			cur=1;
		}
	}
	ans *= powmod(2,c,m);
	ans %= m;
	prll(ans);
	return 0;
}