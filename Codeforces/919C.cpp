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
#define MAX 2000+5
using namespace std;

int a[MAX][MAX];

int foo(vi &v,int k)
{
	int taken = 0;
	int ret = 0;
	if(k>v.size())
		return 0;
	rep(i,0,k)
		taken += v[i];
	if(taken==0)
		ret++;
	rep(i,k,v.size())
	{
		taken += v[i];
		taken -= v[i-k];
		if(taken==0)
			ret++;
	}
	return ret;
}

int main()
{
	int n,m,k;
	si(n); si(m); si(k);
	rep(i,0,n)
	{
		getchar();
		rep(j,0,m)
		{
			char c = getchar();
			if(c=='.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	int ans = 0;
	rep(i,0,n)
	{
		vi v;
		rep(j,0,m)
			v.pb(a[i][j]);
		ans += foo(v,k);
	}
	rep(j,0,m)
	{
		vi v;
		rep(i,0,n)
			v.pb(a[i][j]);
		ans += foo(v,k);
	}
	if(k==1)
		ans /= 2;
	pr(ans);
	return 0;
}