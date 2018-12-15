#include<stdio.h>
#include<math.h>
#define MAX 35
#define sc(x) scanf("%lld",&x)
int main()
{
	long long int a[MAX]={1,0,3},i,j,k,n;
	for(i=4;i<MAX;i+=2)
	{
		a[i]=a[i-2]*3;
		for(j=2;j<=i-2;j+=2)
		{
			a[i]+=2*a[j-2];
		}
	}
	sc(n);
	while(n!=-1)
	{
		printf("%lld\n",a[n]);
		sc(n);
	}
	return 0;
}
