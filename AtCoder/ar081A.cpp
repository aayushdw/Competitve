#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) prllf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long ll
#define F first
#define S second
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define ii pair<ll,ll> 
#define pll pair<ll,ll> 
#define vi vector<ll> 
#define vvi vector< vi > 
#define vl vector<long long ll>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (ll)((double)d + 0.5)
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
#define MAX 100000+5
using namespace std;

vi v;
vi x;
map<ll,ll> m;


int main()
{
	ll n,p;
	sl(n);
	ll ans = 0;
	rep(i,0,n)
	{
		sl(p);
		auto it = m.find(p);
		if(it==m.end())
			m.insert(mp(p,1));
		else
		{
			it->S++;
			if(it->S==2)
				v.pb(p);
			if(it->S==4)
				ans = max(ans,p*p);
		}
	}
	sort(all(v));
	reverse(all(v));
	if(v.size()>=2)
		ans = max(ans,v[0]*v[1]);
	prll(ans);
	return 0;
}