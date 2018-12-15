#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
#define MOD 1000000007
using namespace std;
ll a[1005];
map<ll,ll> v;
typeof(v.begin()) it;
ll solve(ll n,ll m)
{
	it=v.find(n);
	if(it!=v.end())
		return it->second;
	ll ans=0;
	rep(i,0,m)
	if(n%a[i]==0 && n!=a[i])
	ans=max(ans,1+solve(a[i],m)*(n/a[i]));
	//printf("%lld %lld\n",n,ans);
	v.insert(mp(n,ans));
	return ans;
}
int main()
{
	ll t,n,m;
	scll(t);
	while(t--)
	{
		v.clear();
		scll(n); scll(m);
		rep(i,0,m)
		scll(a[i]);
		prll(solve(n,m));
	}
	return 0;
}	