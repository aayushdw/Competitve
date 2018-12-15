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
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 30
using namespace std;

ll a[MAX];
map<ll,ll> PHI;

ll phi(ll n)
{
  ll result=n,i;
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    result-=result/i;
    while(n%i==0)
    n/=i;
  }
  if(n>1)
  result-=result/n;
  return result;
}

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = (x*y<mod) ? x*y : mod + (x*y)%mod; 
        }
        y = (y*y<mod) ? y*y :mod + (y*y)%mod;
        b /= 2;
    }
    return x;
}

ll getPhi(ll m)
{
	auto it = PHI.find(m);
	if(it!=PHI.end())
		return it->S;
	else
		return PHI[m] = phi(m);
}

ll solve(ll l,ll r,ll mod)
{
	if(l==r)
		return (a[l]<mod) ? a[l] : mod + (a[l]%mod);
	if(a[l]==1)
		return 1;
	if(mod==1)
		return 1;
	return powmod(a[l],solve(l+1,r,getPhi(mod)),mod);
}

int main()
{
	ll p,x,q,m=1000000000;
	ll m1 = m+1;
	ll m2 = m+2;
	sl(q);
	while(q--)
	{
		sl(p); sl(x);
		if(!x)
		{
			pr(1);
			continue;
		}
		// if(p==1)
		// {
		// 	pr(1);
		// 	continue;
		// }
		if(!p)
		{
			prll((x+1)%2);
			continue;
		}
		ll l=0,r=min(26ll,x);
		rep(i,0,r)
			a[i] = p;
		ll a1 = solve(l,r-1,m1)%m1;
		ll a2 = solve(l,r-1,m2)%m2;
		ll ans = solve(l,r-1,m)%m;
		if(a1!=a2 || a2!=ans || a1!=ans)
		{
			printf("...");
			printf("%09lld\n",ans);
		}
		else
			prll(solve(l,r-1,m)%m);
	}
	return 0;
}