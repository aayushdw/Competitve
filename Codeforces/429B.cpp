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
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 1000+5
using namespace std;

ll a[MAX][MAX],dp[4][MAX][MAX],n,m;
void foo(ll x,ll y,ll dx,ll dy,ll idx)
{
	dp[idx][x][y]=a[x][y];
	for(int i=x+dx,c=0;c<n;i+=dx,c++)
	dp[idx][i][y]=dp[idx][i-dx][y]+a[i][y];
	for(int i=y+dy,c=0;c<m;i+=dy,c++)
	dp[idx][x][i]=dp[idx][x][i-dy]+a[x][i];
	for(int i=x+dx,c=0;c<n;i+=dx,c++)
	for(int j=y+dy,d=0;d<m;j+=dy,d++)
	dp[idx][i][j]=a[i][j]+max(dp[idx][i-dx][j],dp[idx][i][j-dy]);
}
int main()
{
	sl(n); sl(m);
	rep(i,0,n)
	rep(j,0,m)
	sl(a[i][j]);
	foo(0,0,1,1,0);
	foo(n-1,m-1,-1,-1,1);
	foo(n-1,0,-1,1,2);
	foo(0,m-1,1,-1,3);
	ll ans=0;
	rep(i,1,n-1)
	rep(j,1,m-1)
	ans=max(ans,max(dp[0][i][j-1]+dp[1][i][j+1]+dp[2][i+1][j]+dp[3][i-1][j] , dp[0][i-1][j]+dp[1][i+1][j]+dp[2][i][j-1]+dp[3][i][j+1]));
	cout<<ans;
	return 0;
}
