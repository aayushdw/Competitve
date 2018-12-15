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

ll dp[40][40]={0};

int main()
{
	ll N,H;
	sl(N); sl(H);
	dp[0][0] = 1;
	dp[1][1] = 1;
	rep(n,2,N+1)
		rep(h,1,n+1)
			rep(i,0,n)
				rep(h1,0,i+1)
				rep(h2,0,n-i)
					if(max(h1,h2)==h-1)
						dp[n][h] += dp[i][h1] * dp[n-i-1][h2];

	// rep(i,0,N+1)
	// {
	// 	rep(j,0,N+1)
	// 		printf("%lld ",dp[i][j]);
	// 	printf("\n");
	// }


	ll ans = 0;
	rep(i,H,N+1)
		ans += dp[N][i];
	prll(ans);
	return 0;
}