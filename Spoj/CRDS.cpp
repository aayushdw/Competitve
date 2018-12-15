#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef unsigned long long int ll;
int main()
{
	ll t,n,p;
	sc(t);
	while(t--)
	{
		sc(n);
		p=(n*( (3*n)+1)/2);
		p%=1000007;
		printf("%lld\n",p);
	}
	return 0;
}
