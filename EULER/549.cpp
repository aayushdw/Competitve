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
#define MAX 100000001
// #define MAX 101
using namespace std;

int cur[MAX],ans[MAX];
bitset<MAX> t;

int powInPrime(ll num,ll prime)
{
	int ret = 0;
	ll cur = prime;
	while(num/cur)
	{
		ret += num/cur;
		cur *= prime;
	}
	return ret;
}

int foo(int prime,int pow)
{
	int low = prime, high = prime*pow , mid;
	while(low+1<high)
	{
		mid = (low+high)>>1;
		if(powInPrime((ll)mid,(ll)prime)>=pow)
			high = mid;
		else
			low = mid+1;
	}
	if(powInPrime((ll)low,(ll)prime)>=pow)
		return low;
	else
		return high;
}

void seive()
{
	clr(ans);
	t.reset();
	rep(i,0,MAX) cur[i] = i;
	for(int i=2;i*i<MAX;i++)
	{
		if(t[i]) continue;
		for(int j=i;j<MAX;j+=i)
		{
			t[j] = true;
			int temp = 0;
			while(cur[j]%i==0)
			{
				cur[j] /= i;
				temp++;
			}
			ans[j] = max(ans[j],foo(i,temp));
		}
	}
	rep(i,2,MAX)
		if(cur[i]!=1)
		{
			for(int j=i;j<MAX;j+=i)
				ans[j] = max(ans[j],foo(cur[i],1));
		}
}

void solve()
{
	seive();
	ll ret = 0;
	rep(i,2,MAX)
	{
		ret += ans[i];
		// printf("%d %d\n",i,ans[i]);
	}
	prll(ret);
}

int main()
{
	solve();
	// pr(foo(5,6));
	return 0;
}