#include<stdio.h>
int main()
{
	long long int n,p,zero_count,i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&p);
		zero_count=0;
		while(p%10==0)
		{
			zero_count++;
			p/=10;
		}
		while(p%10==5)
		{
			p*=4;
			while(p%10==0)
			{
				zero_count++;
				p/=10;
			}
		}
		printf("%lld",p);
		while(zero_count--)
		printf("0");
		printf("\n");
	}
	return 0;
}
