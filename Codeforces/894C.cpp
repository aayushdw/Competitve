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

int h[71];

void pre()
{
	vi primes;
	rep(i,2,71)
	{
		bool f = true;
		rep(j,2,i)
			if(i%j==0)
				f = false;
		if(f)
		{
			//pr(i);
			primes.pb(i);
		}
	}
	rep(i,1,71)
	{
		int p = i;
		int x = 0;
		rep(j,0,primes.size())
		{
			bool c = false;
			while(p%primes[j]==0)
			{
				p/=primes[j];
				c = !c;
			}
			x += c;
			x = x << 1;
		}
		h[i] = x;
		// pr(i);
		// pr(h[i]);
	}
}

int main()
{
	pre();
	int n;
	si(n);
	ll p;
	map<ll,ll> m;
	rep(i,0,n)
	{
		sl(p);
		ll hash = h[p];
		vector< pll > v;
		v.pb(mp(h[p],1ll));
		
		tr(it,m)
			v.pb(mp( (it->F)^h[p],it->S ));

		// rep(j,0,v.size())
		// 	printf("(%lld %lld)",v[j].F,v[j].S);
		// cout<<endl;
		pr((int)v.size());

		rep(j,0,v.size())
		{
			auto it = m.find(v[j].F);
			if(it==m.end())
				m.insert(mp(v[j].F,v[j].S));
			else
				it->S += v[j].S;
		}
	}
	auto it = m.find(0);
	ll ans = it==m.end() ? 0 : it->S;
	prll(ans);
	return 0;
}