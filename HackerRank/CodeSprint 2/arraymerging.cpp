#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define MAXN 1205ll
using namespace std;

ll n,m,p,a[MAXN],dp[MAXN][MAXN],C[MAXN][MAXN],fact[MAXN],ans=0;

void pre()
{
	fact[0]=1;
	rep(i,1,MAXN)
	fact[i]=(fact[i-1]*i)%MOD;

	rep(i,0,MAXN)
	C[i][0]=1, C[i][i]=1;
	rep(i,1,MAXN)
	rep(j,1,min(i,MAXN))
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
}

ll findmax(int p)
{
	ll ret=1;
	rep(i,p+1,n)
	if(a[i]>a[i-1])
		ret++;
	else
		break;
	return ret;
}

int main()
{
	clr(C);
	clr(dp);
	pre();
	sl(n);
	rep(i,0,n)
	sl(a[i]);
	for(ll i=n-1;i>=0;i--)
	{
		m=findmax(i);
		for(ll j=1;j<=m;j++)
		{
			if(i+j==n)
			{
				dp[i][j]=1;
				continue;
			}
			for(ll k=1;k<=j;k++)
			{
				p=(C[j][k]*dp[i+j][k])%MOD;
				p*=fact[k];
				dp[i][j]+=p;
				dp[i][j]%=MOD;
			}
			//printf("%lld %lld %lld\n",i,j,dp[i][j]);
		}
	}

	/*rep(i,0,n+1)
	{
		rep(j,1,n+1)
		printf("%3lld",dp[i][j]);
		printf("\n");
	}*/

	rep(i,1,n+1)
	ans+=dp[0][i];
	ans%=MOD;
	printf("%lld",ans);
	return 0;
}