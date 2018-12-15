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
#define MAX 100000+5
using namespace std;



int main()
{
	ll n;
	ll sum = 0;
	ll c = 0;
	sl(n);
	vi a(n,0);
	rep(i,0,n)
	{
		si(a[i]);
		sum += a[i];
		if(!sum)
			c++;
	}

	if(sum%3)
	{
		pr(0);
		return 0;
	}

	if(!sum)
	{
		c--;
		prll((c*(c-1))/2);
		return 0;
	}

	ll cur = 0;
	ll ways = 0;
	unordered_map<ll,ll> m;
	rep(i,0,n)
	{
		cur += a[i];
		if(cur==2*sum/3)
		{
			auto it = m.find(sum/3);
			if(it!=m.end())
				ways += it->S;
		}
		auto it = m.find(cur);
		if(it==m.end())
			m.insert(mp(cur,1));
		else
			it->S++;
	}
	prll(ways);
	return 0;
}