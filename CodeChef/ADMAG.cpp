#include<stdio.h>
#define MAX 500
long long int a[MAX]={1,1};
#define sc(x) scanf("%lld",&x)
int main()
{
	long long int i,t,n;
	for(i=2;i<MAX;i++)
	a[i]=a[i-1]+a[i-2];
	sc(t);
	while(t--)
	{
		sc(n);
		i=0;
		while(a[i]<=n)
		i++;
		printf("%d\n",i-1);
	}
	return 0;
}
