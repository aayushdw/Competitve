#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int n,i,sum=0,t,a,b;
	sc(t);
	while(t--)
	{
		sc(n);
		sum=0;
		for(i=1;i<=n/2;i++)
		{
			printf("%d %d\n",i,n/i);
			sum+=i*(n/i-1);
		}
		printf("%d\n",sum);
	}
}
