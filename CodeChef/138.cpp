#include<stdio.h>
int main()
{
	int count=0,i;
	long long int l=1,x=0,li,xi,sum=0;
	for(i=0;i<12;i++)
	{
		xi=-9*x-4*l-4;
		li=-20*x-9*l-8;
		l=li;
		count++;
		x=xi;
		printf("%d %lld %lld\n",count,li,xi);
		sum+=(l>0?l:-
		l);
	}
	printf("%lld",sum);
	return 0;
}
