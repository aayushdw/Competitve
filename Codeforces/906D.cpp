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
#define MAX 100000+5
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
            x = (x*y<mod) ? x*y : mod + (x*y)%mod;  //(x*y)%mod;
        }
        y = (y*y<mod) ? y*y :mod + (y*y)%mod; //(y*y)%mod;
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
	ll n,m,q;
	sl(n); sl(m);
	rep(i,0,n)
		sl(a[i]);
	sl(q);
	while(q--)
	{
		ll l,r;
		sl(l); sl(r);
		l--; r--;
		prll(solve(l,r,m)%m);
	}
	return 0;
}