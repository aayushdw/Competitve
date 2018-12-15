#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int t,n,k;
	double p;
	sc(t);
	while(t--)
	{
		sc(n); sc(k);
		p=(n+1)/2.0;
		printf("%0.6lf\n",p);
	}
	return 0;
}
