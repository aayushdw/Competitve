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
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 200000+5
using namespace std;

void solve()
{
	ll n;
	sl(n);
	vl cnt(MAX,0);
	vl a(n);
	rep(i,0,n)
	{
		sl(a[i]);
		cnt[a[i]]++;
	}
	ll ans = 0;
	rep(i,0,n)
	{
		cnt[a[i]]--;
		rep(j,i+1,n)
		{
			cnt[a[j]]--;
			ll prod = a[i]*a[j];
			if( prod < MAX )
				ans += cnt[prod];
			cnt[a[j]]++;
		}
		cnt[a[i]]++;
	}
	// prll(ans);
	// prll(cnt[0]);
	// prll(cnt[1]);
	ans -= (cnt[0]*(cnt[0]-1)*(cnt[0]-2))/3;
	ans -= (cnt[1]*(cnt[1]-1)*(cnt[1]-2))/3;
	ans -= (n-cnt[0])*(cnt[0]*(cnt[0]-1))/2;
	prll(ans);
	return;
}

int main()
{
	ll t;
	sl(t);
	rep(i,1,t+1)
	{
		printf("Case #%lld: ",i);
		solve();
	}
	return 0;
}