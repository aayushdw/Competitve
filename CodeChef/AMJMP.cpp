#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define MAX 5000+5
int h[MAX];
int dp[MAX][MAX];
int max(int a,int b)
{
	return a>b?a:b;
}
/*int jump(int i,int j)
{
	if(dp[i][j]==-1)
	return 0;
	if(i<j)
	{
		return 1+jump(dp[i][j]-1,i+1);
	}
	else
	return 1+jump(dp[i][j]+1,i-1);
}*/
int main()
{
	int n,i,j,a,b;
	sc(n);
	for(i=1;i<=n;i++)
	{
		sc(h[i]); 
		dp[i][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j+i<=n;j++)
		{
			if(h[j+i]>=h[j])
			dp[j][j+i]=dp[j][j+i-1];
			else
			dp[j][j+i]=max(1+dp[j+i][j+1],dp[j][j+i-1]);
			//printf("%d %d %d\n",j,j+i,dp[j][j+i]);
		}
		for(j=n;j-i>0;j--)
		{
			if(h[j-i]>=h[j])
			dp[j][j-i]=dp[j][j-i+1];
			else
			dp[j][j-i]=max(1+dp[j-i][j-1],dp[j][j-i+1]);
			//printf("%d %d %d\n",j,j-i,dp[j][j-i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",max(dp[i][n],dp[i][1]));
	}
	return 0;
}
