#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define MAX 50
int main()
{
	long long int a[MAX]={1,1,5},i,j,t,n;
	for(i=3;i<MAX;i++)
	{
		a[i]=a[i-1]+a[i-2];
		for(j=i-2;j>=0;j--)
		a[i]+=2*a[j];
		for(j=i-2;j>=0;j-=2)
		a[i]+=a[j];
	}
	sc(t);
	for(i=1;i<=t;i++)
	{
		sc(n);
		printf("%lld %lld\n",i,a[n]);
	}
	return 0;
}
