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
#define MAX 200000+5
using namespace std;

ll f[MAX];

void pre()
{
	f[0]=1;
	rep(i,1,MAX)
	{
		f[i]=i*f[i-1];
		f[i]%=MOD;
	}
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


ll ways(ii start, ii end)
{
	ll m=end.F-start.F;
	ll n=end.S-start.S;
	ll ret=f[m+n];
	ret*=powmod(f[m],MOD-2,MOD);
	ret%=MOD;
	ret*=powmod(f[n],MOD-2,MOD);
	ret%=MOD;
	return ret;
}

int main()
{
	pre();
	ll h,w,a,b;
	cin>>h>>w>>a>>b;
	ll ans=0;
	rep(i,1,h-a+1)
	{
		ll p=ways(mp(1,1),mp(i,b));
		p*=ways(mp(i,b+1),mp(h,w));
		p%=MOD;
		ans+=p;
		ans%=MOD;
	}
	prll(ans);	
	return 0;
}