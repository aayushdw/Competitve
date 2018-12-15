#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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

#define MOD 100000000
#define INF 10000000000000000
#define MAX 100+5
using namespace std;

ll dp[MAX][MAX][12][12],x,y;

ll solve(ll n1, ll n2, ll k1, ll k2)
{

	//printf("%lld %lld %lld %lld\n",n1,n2,k1,k2);

	if(dp[n1][n2][k1][k2]>=0)
		return dp[n1][n2][k1][k2];

	if(n1==0 && n2>y)
		return dp[n1][n2][k1][k2]=0;

	if(n2==0 && n1>x)
		return dp[n1][n2][k1][k2]=0;

	if(n1==0 || n2==0)
		return dp[n1][n2][k1][k2]=1;

	//if(last)

	ll ret=0;

	if(!k1)
		ret=solve(n1,n2-1,x,y-1);
	else if(!k2)
		ret=solve(n1-1,n2,x-1,y);
	else
		ret=solve(n1,n2-1,x,k2-1)+solve(n1-1,n2,k1-1,y);

	return dp[n1][n2][k1][k2]=ret%MOD;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll n1,n2,k1,k2;
	sl(n1); sl(n2); sl(k1); sl(k2);
	x=k1, y=k2;
	printf("%lld",solve(n1,n2,k1,k2));
	return 0;
}