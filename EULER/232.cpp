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

#define PTS 2

double dp[PTS+1][PTS+1][2];

double get(int i,int j)
{
	double ret = 0.0;
	int t = 2;
	while(t<=128*8)
	{
		double temp = ( 2*dp[i][min(PTS,j+t/2)][0] + (t-1)*dp[i+1][j][1] ) / (t+1);
		temp *= dp[i][min(PTS,j+t/2)][0];
		ret = max(ret,temp);
		t *= 2;
	}
	return ret;
}

int main()
{
	clr(dp);
	rep(i,0,PTS)
	{
		dp[PTS][i][0] = dp[PTS][i][1] = 0.0;
		dp[i][PTS][0] = dp[i][PTS][1] = 1.0;
	}
	for(int i=PTS-1;i>=0;i--)
		for(int j=PTS-1;j>=0;j--)
		{
			dp[i][j][1] = get(i,j);
			dp[i][j][0] = (dp[i+1][j][1] + dp[i][j][1])/2;
		}

	rep(i,0,PTS+1)
	{
		rep(j,0,PTS+1)
			printf("%0.4lf ",dp[i][j][0]);
		printf("\n");
	}
	printf("\n");
	rep(i,0,PTS+1)
	{
		rep(j,0,PTS+1)
			printf("%0.4lf ",dp[i][j][1]);
		printf("\n");
	}
	printf("\n");

	printf("%0.8lf\n",dp[0][0][0]);
	return 0;
}