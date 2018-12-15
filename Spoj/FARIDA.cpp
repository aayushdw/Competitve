#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef long long int ll;
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll t,p,i,n,a,b,temp,j;
	sc(t);
	for(j=1;j<=t;j++)
	{
		sc(n);
		if(n==0)
		{
			printf("Case %lld: 0\n",j);
			continue;
		}
		if(n==1)
		{
			sc(b);
			printf("Case %lld: %lld\n",j,b);
			continue;
		}
		sc(a); sc(b);
		for(i=2;i<n;i++)
		{
			sc(p);
			temp=b;
			b=max(b,a+p);
			a=temp;
		}
		b=max(a,b);
		printf("Case %lld: %lld\n",j,b);
	}
	return 0;
}
