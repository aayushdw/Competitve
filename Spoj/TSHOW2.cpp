#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef long long int ll;
int main()
{
	ll t,n,i;
	int a[61]={0,1};
	for(i=2;i<61;i++)
	a[i]=(a[i-1]+a[i-2])%10;
	sc(t);
	while(t--)
	{
		sc(n);
		n--;
		n%=60;
		printf("%d\n",a[n]);
	}
	return 0;
}
