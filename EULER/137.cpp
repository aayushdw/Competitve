#include<stdio.h>
#include<math.h>
int check(long long int p)
{
	long long int a=sqrt(p);
	if(a*a==p)
	return 1;
	return 0;
}
int main()
{
	long long int p,a,count=0;
	for(p=1;count<15;++p)
	{
		a=5*p*p+2*p+1;
		if(a<0)
		{
			printf("%lld\n",p);
			printf("abort\n");
			return 0;
		}
		if(check(a))
		{
			count++;
			printf("%lld\n",p);
		}
	}
	printf("%lld",p-1);
	return 0;
}
