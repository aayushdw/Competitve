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
#define INF 1<<25
#define MAX 80+5
using namespace std;

int dp[MAX][MAX][MAX];
vii G[MAX];

int main()
{
	int n,k,m;	
	si(n); si(k); si(m);
	rep(i,0,MAX)
	rep(j,0,MAX)
	rep(x,0,MAX)
	dp[i][j][x]=INF;
	if(k==1)
	{
		printf("0");
		return 0;
	}
	while(m--)
	{
		int u,v,c;
		si(u); si(v); si(c);
		G[u].pb(mp(v,c));
		dp[u][v][1]=min(dp[u][v][1],c);
	}

	rep(npath,2,k)
	{
		rep(u,1,n+1)
		{
			rep(x,0,G[u].size())
			{
				int v=G[u][x].F;
				int c=G[u][x].S;
				if(v>u)
				{
					rep(i,u+1,v)
					dp[u][v][npath]=min( dp[u][v][npath] , dp[v][i][npath-1]+c);
				}
				else
				{
					rep(i,v+1,u)
					dp[u][v][npath]=min( dp[u][v][npath] , dp[v][i][npath-1]+c);
				}
				//printf("%d %d %d %d %d\n",u,v,c,npath,dp[u][v][npath]);
			}
		}
	}

	/*rep(x,1,k+1)
	{
		rep(i,1,n+1)
		rep(j,1,n+1)
		printf("%d %d %d\n",i,j,dp[i][j][x]);
		printf("\n");
	}*/ 


	int ans=INF;
	rep(i,1,n+1)
	rep(j,1,n+1)
	ans=min(dp[i][j][k-1],ans);
	if(ans>=INF)
		ans=-1;
	pr(ans);	
	return 0;
}