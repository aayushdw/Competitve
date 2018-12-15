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
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD1 1000000007
#define MOD2 1000000009
#define BASE 31
#define INF 4000000000000000000
#define MAX 75005
using namespace std;

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

ll pow1[MAX],pow2[MAX],invPow1[MAX],invPow2[MAX];

void pre()
{
	rep(i,0,MAX)
	{
		pow1[i] = powmod(i,i,MOD1);
		invPow1[i] = powmod(pow1[i],MOD1-2,MOD1);

		pow2[i] = powmod(i,i,MOD2);
		invPow2[i] = powmod(pow2[i],MOD2-2,MOD2);
	}
}

bool isIsomprphic(ll a,ll b,ll x,ll y,vector< pll > &hash)
{
	pll hash1 = hash[b];
	hash1.F *= powmod(hash[a-1].F,MOD1-2,MOD1);
	hash1.S *= powmod(hash[a-1].S,MOD2-2,MOD2);

	pll hash2 = hash[y];
	hash2.F *= powmod(hash[x-1].F,MOD1-2,MOD1);
	hash2.S *= powmod(hash[x-1].S,MOD2-2,MOD2);

	printf("(%lld %lld) = [%lld %lld], (%lld %lld) = [%lld %lld]\n",a,b,hash1.F,hash1.S,x,y,hash2.F,hash2.S);

	return hash1 == hash2;
}

void solve()
{
	ll n;
	sl(n);
	vl a(n,0);
	rep(i,0,n)
	{
		sl(a[i]);
		a[i]--;
	}
	vl c(n,0);
	vector< pll > hash;
	hash.pb(mp(1ll,1ll));
	rep(i,0,n)
	{
		ll p = hash.back().F , q = hash.back().S;

		p *= invPow1[c[a[i]]];
		q *= invPow2[c[a[i]]];
		p %= MOD1; q %= MOD2;

		c[a[i]] ++;

		p *= pow1[c[a[i]]];
		q *= pow2[c[a[i]]];
		p %= MOD1; q %= MOD2;

		printf("%d %lld %lld\n",i,p,q);

		hash.pb(mp(p,q));
	}

	ll q;
	sl(q);
	ll last = 0;
	rep(i,1,q+1)
	{
		ll x,z,c,d;
		sl(x); sl(z); sl(c); sl(d);
		ll k = min(n-x , n-z) + 1;
		ll y = x + (c + d *last)%k;
		ll t = z + (c + d * last) % k;
		bool f = isIsomprphic(x,y,z,t,hash);
		if(f)
		{
			printf("YES\n");
			last = i;
		}
		else
			printf("NO\n");
	}
}

int main()
{
	pre();
	int t;
	si(t);
	while(t--)
		solve();
	return 0;
}