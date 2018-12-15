#include<stdio.h>
int main()
{
	long long int x,count,max=0,n;
	for(n=1;;n++)
	{
		if(n%1000==0)
		printf("%lld %lld\n",n,max);
		count=0;
		for(x=n+1;x<2*n;x++)
		{
			if((n*x)%(x-n)==0)
			count++;
		}
		if(max<count)
		max=count;
		//printf("%lld %lld\n",n,count+1);
		if(count>1000)
		{
			printf("%lld",n);
			return 0;
		}
	}
	return 0;
}
