#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef long long int ll;
ll modExpo(ll a,ll b,ll MOD)
{
	ll x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x*=y;
			x%=MOD;
		}
		y*=y;
		y%=MOD;
		b/=2;
	}
	return x;
}
int  main()
{
	ll t,n,i,k,MOD=1000000007;
	sc(t);
	for(i=1;i<=t;i++)
	{
		sc(n);
		if(n==1)
		{
			printf("Case %lld: 1\n",i);
			continue;
		}
		k=modExpo(2,n-2,MOD);
		k*=(n+1);
		k%=MOD;
		printf("Case %lld: %lld\n",i,k);
	}
	return 0;
}
