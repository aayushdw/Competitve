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
#define LIM 100ll
#define MAX 10000000ll
using namespace std;

bitset<MAX> t;
vl smpf(MAX,MOD);
vl sum(MAX,0);
vl ans(MAX,0);

void sieve()
{
	t.reset();
	t[0] = t[1] = true;
	t[2] = false;
	smpf[2] = 2;
	for(ll i=4;i<MAX;i+=2)
	{
		smpf[i] = 2;
		t[i] = true;
	}
	for(ll i=3;i*i<MAX;i+=2)
	{
		if(t[i])	continue;
		for(ll j=i+i+i;j<MAX;j+=i+i)
		{
			smpf[j] = min(smpf[j],i);
			t[j] = true;
		}
	}
	for(int i=3;i<MAX;i+=2)
		if(!t[i])
			smpf[i] = i;
	for(int i=2;i<MAX;i++)
		ans[i] = ans[i-1] + smpf[i];
}

int main()
{
	sieve();
	return 0;
	ll q;
	sl(q);
	while(q--)
	{
		ll n;
		sl(n);
		prll(ans[n]);
	}
	return 0;
}