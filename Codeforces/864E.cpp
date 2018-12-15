#include<bits/stdc++.h>
 
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
#define MAX 2000+5
using namespace std;

vector< pair< int,ii > > v;

int dp[101][MAX],t[101],d[101],p[101];

int main()
{
	int n;
	si(n);
	rep(i,0,n)
		si(t[i]);
	rep(i,0,n)
		si(d[i]);
	rep(i,0,n)
		si(p[i]);
	rep(i,0,n)
		v.pb(mp(d[i],mp(t[i],p[i])));
	sort(all(v));

	clr(dp);
	rep(j,d[0],MAX)
		dp[0][j] = p[0];

	rep(i,1,n)
	{
		d[i] = v[i].F;
		t[i] = v[i].S.F;
		p[i] = v[i].S.S;
		rep(j,1,d[i]+1)
		{
			if(j<t[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],p[i]+dp[i-1][j-t[i]]);
		}
		rep(j,d[i]+1,MAX)
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	}

	rep(i,0,n)
	{
		rep(j,0,10)
			printf("%d ",dp[i][j]);
		printf("\n");
	}

	pr(dp[n-1][MAX-1]);
	return 0;
}