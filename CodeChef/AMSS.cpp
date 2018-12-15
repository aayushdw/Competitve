#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define MOD 1000000007
#define MAX 5000+5
ll nCr[MAX][MAX];
ll pow25[MAX]={1};
ll dp[MAX][MAX];
int main()
{
	ll i,j,sum,t,p;
	for(i=1;i<MAX;i++)
	for(j=1;j<MAX;j++)
	{
		if(i==0||j==i)
		nCr[i][j]=1;
		else
		nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
	}
	for(i=1;i<MAX;i++)
	{
		pow25[i]=(pow25[i-1]*25)%MOD;
	}
	/*for(n=0;k<MAX;k++)
	{
		for(k=0;k<=n;k++)
		{
			dp[n][k]=(26*pow25[k-1])%MOD;
			dp[n][k]=(dp[n][k]*nCr[n-1][k-1])%MOD;
		}
	}*/
	for(n=1;n<MAX;n++)
	{
		for(k=1;k<=n;k++)
		{
			dp[n][k]=(26*pow25[k-1]*nCr[n][k])%MOD
		}
	}
	
	sc(t);
	while(t--)
	{
		sc(p);
		prll(arr[p]);
	}
	return 0;
}
