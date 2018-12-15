#include<stdio.h>
#define ll long long int
#define sc(x) scanf("%lld",&x)
#define MOD 1000000007
int main()
{
	ll i,t,n,k,p,pow2[100005]={1};
	for(i=1;i<100005;i++)
	{
		pow2[i]=(pow2[i-1]*2)%MOD;
	}
	sc(t);
	while(t--)
	{
		sc(n);
		ll arr[n+1], a[n+1];
		sc(a[0]);
		arr[0]=(2*a[0])%MOD;
		for(i=1;i<=n;i++)
		{
			sc(a[i]);
			arr[i]=(arr[i-1]+pow2[i]*a[i])%MOD;
		}
		/*for(i=0;i<n;i++)
		printf("%d ",arr[i]);*/
		ll sum=0;
		for(i=0;i<n;i++)
		{
			p=(pow2[n-i-1]*arr[i])%MOD;
			p=(p*a[i+1])%MOD;
			sum=(sum+p)%MOD;
		}
		printf("%lld\n",sum);
	}
}
