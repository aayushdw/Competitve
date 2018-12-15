#include<stdio.h>
#include<math.h>
#define MAX 1000000000
int check(long long int p)
{
	long long int a=sqrt(p);
	if(a*a==p)
	return 1;
	return 0;
}
int main()
{
	long long int a,b,sum=0;
	for(a=2;a<=(MAX-1)/3;a++)
	{
		b=(3*a+1)*(a-1);
		if(b<0)
		{
			printf("abort");
			return 0;
		}
		if(b%16)
		continue;
		if(check(b/16))
		{
			sum+=3*a+1;
		printf("%lld %lld %lld %lld\n",a,a,a+1,sum);
		}
	}
	for(a=2;a<=(MAX+1)/3;a++)
	{
		b=(3*a-1)*(a+1);
		if(b<0)
		{
			printf("abort");
			return 0;
		}
		if(b%16)
		continue;
		if(check(b/16)){
			sum+=3*a-1;
		printf("%lld %lld %lld %lld\n",a-1,a,a,sum);
		}
		
	}
	printf("%lld",sum);
	return 0;
}
