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

ll a[MAX][MAX]={0};
ll m[MAX];
ll c[MAX][26]={0};
ll dp[MAX]={0};
ll ans1[MAX]={0},ans2[MAX];
int main()
{
	ll n;
	string s;
	sl(n);
	cin>>s;
	rep(i,0,26)
	sl(m[i]);
	c[0][s[0]-'a']=1;
	rep(i,1,s.length())
	{
		rep(j,0,26)
		c[i][j]=c[i-1][j];
		c[i][s[i]-'a']++;
		/*rep(j,0,26)
		printf("%lld ",c[i][j]);
		printf("\n");*/
	}
	rep(i,0,n)
	rep(j,i,n)
	{
		bool flag=true;
		rep(k,0,26)
		if(( (i==0 && c[j][k]) || (c[j][k]-c[i-1][k]) ) && m[k] < j-i+1)
		{
			//printf("%d %d %d %lld\n",i,j,k,c[j][k]);
			flag=false;
			break;
		}
		if(flag)
		{
			a[i][j]=1;
			//printf("%d %d\n",i,j);
		}
		else
			a[i][j]=0;
	}
	rep(i,0,MAX)
	ans2[i]=INT_MAX;
	dp[0]=1; ans1[0]=1; ans2[0]=1;
	rep(i,1,n)
	rep(j,0,i+1)
	{
		//printf("i=%d\n",i);
		if(a[j][i])
		{
			if(j==0)
			{
				dp[i]++;
				dp[i]%=MOD;
				ans2[i]=1;
			}
			else
			{
				dp[i]+=dp[j-1];
				dp[i]%=MOD;
				ans2[i]=min(ans2[i],ans2[j-1]+1);
			}
			ans1[i]=max(ans1[i-1],max(ans1[i],(ll)(i-j+1)));
			//printf("j=%d %lld\n",j,dp[i]);
		}
	}
	prll(dp[n-1]); prll(ans1[n-1]); prll(ans2[n-1]);
	return 0;
}