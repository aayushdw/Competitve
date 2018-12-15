#include<stdio.h>
#define ll long long int
#define sc(x) scanf("%lld",&x)
#define MAX 1024
#define MOD 1000000007
ll a[MAX+1][MAX+1]={1};
int main()
{
	ll i,j,n,p,t;
	for(i=1;i<=MAX;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for(i=1;i<=MAX;i++)
	for(j=0;j<=i-1;j++)
	a[i][j]=(a[i-1][j-1]+a[i-1][j])%MOD;
	sc(t);
	while(t--)
	{
		sc(n);
		ll sum=0;
		for(i=0;i<n;i++)
		sc(p);
		for(i=0;i<n;i++)
		if(i<n-i)
		{
			sum+=a[n][i];
			sum%=MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

