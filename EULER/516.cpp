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
 
#define MOD 4294967296
#define INF 4000000000000000000
#define MAX 101ll
using namespace std;

vl hamming;

ll mod;
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll a[]={1996011519951206ll,1995120619960115ll,1995100319960115ll,195100319951206ll,1996011519951003ll};
ll multi(ll x,ll y)
{
	ll w=x*y-mod*((ll)(double(x)*y/mod+1e-3));
	while(w<0)
		w+=mod;
	while(w>=mod)
		w-=mod;
	return w;
}
ll pow(ll x,ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
			t=multi(t,x);
		x=multi(x,x);
		y>>=1;
	}
	return t;
}
bool judge(ll n)
{
	if(n==2) return true;
	if(n<2||!(n&1)) return false;
	for(int i=0;i<25;i++)
		if(n%b[i]==0&&n!=b[i])
			return false;
	mod=n;
	int t=0;
	ll u=n-1;
	while(!(u&1)) t++,u>>=1;
	for(int i=0;i<5;i++)	//Increase for Accuracy
	{
		ll x=a[i]%(n-1)+1;
		x=pow(x,u);
		ll y=x;
		for(int j=1;j<=t;j++)
		{
			x=multi(x,x);
			if(x==1&&y!=1&&y!=n-1)
				return false;
			y=x;
		}
		if(x!=1) return false;
	}
	return true;
}

bool check(ll a,ll b,ll c)
{
	double aa = a*1.0;
	double bb = b*1.0;
	double cc = c*1.0;
	return aa*bb<cc;
}

void solve()
{
	stack< vl > s;
	vl v(3);
	v[0] = 1;
	s.push(v);
	v[0] = 0; v[1] = 1;
	s.push(v);
	v[1] = 0; v[2] = 1;
	s.push(v);
	set<ll> S;
	ll c = 0;
	while(!s.empty())
	{
		v = s.top();
		s.pop();
		ll num = std::pow(2ll,v[0])*std::pow(3ll,v[1])*std::pow(5ll,v[2]);
		hamming.pb(num);
		{
			v[0]++;
			if(num*2<MAX && S.find(num*2)==S.end())
			{
				s.push(v);
				S.insert(num*2);
			}
			v[0]--;
		}
		
		{
			v[1]++;
			if(num*3<MAX && S.find(num*3)==S.end())
			{
				s.push(v);
				S.insert(num*3);
			}
			v[1]--;
		}
		
		{
			v[2]++;
			if(num*5<MAX && S.find(num*5)==S.end())
			{
				s.push(v);
				S.insert(num*5);
			}
			v[2]--;
		}
	}
	sort(all(hamming));
	// pr((int)hamming.size());

	// rep(i,0,hamming.size())
	// {
	// 	printf("%lld ",hamming[i]);
	// }
	// printf("\n\n");

	vl allowedPrimes;
	rep(i,0,hamming.size())
		if(judge(hamming[i]+1))
			allowedPrimes.pb(hamming[i]+1);

	// pr((int)allowedPrimes.size());

	// rep(i,0,allowedPrimes.size())
	// {
	// 	printf("%lld ",allowedPrimes[i]);
	// }
	// printf("\n\n");

	vl print;

	stack< pll > foo;
	ll ans = 0;
	rep(i,0,hamming.size())
	{
		foo.push(mp(hamming[i],2));
		ans += hamming[i];
		ans %= MOD;
		// print.pb(hamming[i]);
	}
	foo.push(mp(1,2));

	// return;
	ll cnt=0;

	while(!foo.empty())
	{
		ll num = foo.top().F;
		ll idx = foo.top().S;
		foo.pop();
		if(idx==allowedPrimes.size())
			continue;
		if(num*allowedPrimes[idx+1]<MAX && check(num,allowedPrimes[idx+1],MAX))
			foo.push(mp(num,idx+1));

		if(num*allowedPrimes[idx+1]<0)
		{
			printf("%lld %lld %lld\n",num,allowedPrimes[idx+1],num*allowedPrimes[idx+1]);
			break;
		}

		if(num*allowedPrimes[idx]<MAX)
		{
			cnt++;
			num *= allowedPrimes[idx];
			ans += num;
			ans %= MOD;
			if(num*allowedPrimes[idx+1]<MAX && check(num,allowedPrimes[idx+1],MAX))
				foo.push(mp(num,idx+1));
			// prll(num);
			// print.pb(num);
		}
	}
	sort(all(print));
	// rep(i,0,print.size())
	// 	prll(print[i]);
	printf("%lld %lld\n",ans+1,cnt);
}

int main()
{
	solve();
	return 0;
}