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
#define INF 4000000000000000000
#define MAX 5000+5
using namespace std;

ll ncr[MAX][MAX];

void pre()
{
	clr(ncr);
	rep(i,0,MAX)
		rep(j,0,i+1)
		{
			if(j==i||j==0)	ncr[i][j] = 1;
			else	ncr[i][j] = ( ncr[i-1][j] + ncr[i-1][j-1] ) % (MOD-1);
		}
	return;
}

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

void solve()
{
	ll n,k;
	sl(n); sl(k);
	vl v;
	rep(i,0,n)
	{
		ll p; sl(p);
		v.pb(p);
	}
	sort(all(v));
	vl cnt;
	cnt.resize(n);
	ll ans = 1;
	rep(i,0,n)
	{
		cnt[i] = ncr[n-1][k-1];
		if(n-i-1 >= k-1)	cnt[i] -= ncr[n-i-1][k-1];
		if(i >= k-1)		cnt[i] -= ncr[i][k-1];
		
		cnt[i] = ( (cnt[i] % (MOD-1) ) + (MOD-1) ) % (MOD-1);
		if(cnt[i])
			ans *= powmod(v[i],cnt[i],MOD);
		ans %= MOD;
	}
	prll(ans);
	return;
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