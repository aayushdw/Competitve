#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int
#define MOD 1000000007
#define MAX 1005
ll arr[MAX][MAX]={0};
int main()
{
	ll n,m,c,i,j,p,k;
	sc(n); sc(m); sc(c);
	ll u[MAX]={0}, l[MAX]={0};
	for(i=0;i<n;i++)
	{
		sc(p);
		u[p]++;
	}
	for(i=0;i<m;i++)
	{
		sc(p);
		l[p]++;
	}
	for(i=0;i<MAX;i++)
	arr[0][i]=(u[i]*l[i])%MOD;
	for(i=1;i<=c+1;i++)
	{
		k=arr[i-1][i];
		for(j=i+1;j<MAX;j++)
		{
			arr[i][j]=(arr[0][j]*k)%MOD;
			k+=arr[i-1][j];
			k%=MOD;
		}
		if(i-1)
		printf("%lld ",k);
	}
	/*for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%d ",arr[i][j]);
		printf("\n");
	}*/
	return 0;
}
