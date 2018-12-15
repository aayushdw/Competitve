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
#define MAX 30+5
using namespace std;

int lol[MAX][MAX],dp[MAX][MAX],a[MAX],n,k;


void pre()
{
	clr(lol);
	rep(i,0,n)
	{
		rep(j,i+1,n)
		{
			rep(k,i+1,j)
				lol[i][j] = max(lol[i][j],a[j]-a[k]);
			lol[i][j] = max(lol[i][j],lol[i][j-1]);
			lol[i][j] = max(lol[i][j],a[j]-a[i]);
		}
	}
	
	return;
}

int solve()
{
	clr(dp);
	rep(i,1,n)
	{
		rep(j,0,i)
		dp[1][i] = max(dp[1][i],lol[j][i]);
	}
	rep(i,2,k+1)
	{
		rep(j,1,n)
		{
			rep(k,0,j)
				dp[i][j] = max(dp[i][j],dp[i-1][k] + lol[k+1][j]);
		}
	}
	int ret = 0;
	rep(i,1,k+1)
	{
		rep(j,0,n)
		ret = max(ret,dp[i][j]);
	}
	return ret;
}
 
int main()
{
    int q;
    si(q);
    while(q--)
    {
    	si(k); si(n);
    	rep(i,0,n)
    	si(a[i]);
    	pre();
    	pr(solve());
    }
    return 0;
}