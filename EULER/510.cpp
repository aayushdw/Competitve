#include<stdio.h>
#define MAX 100
#define ll long long int
int main()
{
	ll a,b,sum=0,p,x;
	for(a=1;a*a<=MAX;a++)
	{
		p=MAX/(a*a);
		for(b=1;b<=a;b++)
		{
			for(x=1;x<=p;x++)
			{
				if((a*a*b*b)%(a*a+b*b+2*a*b)==0)
				{
					//if(a*a*x+b*b*x+(a*a*b*b*x)/(a*a+b*b+2*a*b)<=MAX)
					sum+=a*a*x+b*b*x+(a*a*b*b*x)/(a*a+b*b+2*a*b);
					printf("%lld %lld %lld\n",a*a*x,b*b*x,(a*a*b*b*x)/(a*a+b*b+2*a*b));
				}
			}
		}
		
	}
	printf("%lld",sum);
}
