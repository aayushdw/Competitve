#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int t,i,n,k,max,p;
	sc(t);
	while(t--)
	{
		sc(n); sc(k);
		max=0;
		for(i=2;i<=k;i++)
		{
			p=n%i;
			if(p>max)
			max=p;
		}
		printf("%d\n",max);
	}
	return 0;
}
