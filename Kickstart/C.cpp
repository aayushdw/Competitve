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
// #define ii pair<int,int> 
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
#define MAX 100000+5
using namespace std;

int dp[41][41][41][41], mindp[41][41][41][41];
int v[41][41];

int solve(int i,int j,int ii,int jj)
{
	if(dp[i][j][ii][jj]!=-1)
		return dp[i][j][ii][jj];

	printf("(%d,%d,%d,%d)\n",i,j,ii,jj);

	if(i==ii && j==jj)
	{
		printf("adsfaf");
		mindp[i][j][ii][jj] = v[i][j];
		return dp[i][j][ii][jj] = 0;
	}
	rep(_i,i,ii)
	{
		solve(i,j,_i,jj);
		solve(_i+1,j,ii,jj);
		mindp[i][j][ii][jj] = min( mindp[i][j][_i][jj] , mindp[_i+1][j][ii][jj] );
		if(dp[i][j][ii][jj] != -1)
			dp[i][j][ii][jj] = min( solve(i,j,_i,jj) + solve(_i+1,j,ii,jj) + mindp[i][j][ii][jj] \
				, dp[i][j][ii][jj] );
		else
			dp[i][j][ii][jj] = solve(i,j,_i,jj) + solve(_i+1,j,ii,jj) + mindp[i][j][ii][jj];
	}
	rep(_j,j,jj)
	{
		solve(i,j,ii,_j);
		solve(i,_j+1,ii,jj);
		mindp[i][j][ii][jj] = min( mindp[i][j][i][_j] , mindp[i][_j+1][ii][jj] );
		if(dp[i][j][ii][jj] != -1)
			dp[i][j][ii][jj] = min( solve(i,j,ii,_j) + solve(i,_j+1,ii,jj) + mindp[i][j][ii][jj] \
				, dp[i][j][ii][jj] );
		else
			dp[i][j][ii][jj] = solve(i,j,ii,_j) + solve(i,_j+1,ii,jj) + mindp[i][j][ii][jj];
	}
	return dp[i][j][ii][jj];
}

int main()
{
	int t,n,m;
	si(t);
	for(int tt=1;tt<=t;tt++)
	{
		si(n); si(m);
		rep(i,0,n)
			rep(j,0,m)
				si(v[i][j]);
		memset(dp,-1,sizeof(dp));
		solve(0,0,n-1,m-1);
		printf("Case #%d: %d\n",tt,dp[0][0][n-1][m-1]);
		rep(i,0,n)
			rep(j,0,n)
				rep(ii,0,n)
					rep(jj,0,n)
						printf("mindp[%d][%d][%d][%d] = %d\n",i,j,ii,jj,mindp[i][j][ii][jj]);
	}
	return 0;
}