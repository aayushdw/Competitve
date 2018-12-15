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
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 6
using namespace std;

ll LCM(ll a,ll b)
{
	ll g = __gcd(a,b);
	return a*b / g;
}

int main()
{
	ll ans = 0;
	for(ll i=6;i<=MAX;i++)
	{
		ll num = 1000000; //pow(4ll,i);
		ll lcm = 1;
		for(ll j=1;j<=i;j++)
			lcm = LCM(lcm,j);
		ans += (num-2) / lcm;
		lcm = LCM(lcm,i+1);
		ans -= (num-2) / lcm;
	}
	prll(ans);
	return 0;
}





//(2*pi - (pi/2 + arctan((3-y)/x) + arctan((4-x)/y) ) ) / (2*pi)