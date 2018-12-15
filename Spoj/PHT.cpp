#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lld",&x);
typedef long long int ll;
ll solve(ll p)
{
	double k=sqrt(p+1);
	ll a=(int)k;
	return a-1;
}
int main()
{
	ll t,k,i;
	sc(t);
	for(i=1;i<=t;i++)
	{
		sc(k);
		printf("Case %lld: %lld\n",i,solve(k));
	}
	return 0;
}
