#include<stdio.h>
#define ll long long int
int main()
{
	ll i,count=0,a,b,c,t,p;
	for(i=27;count<124;i+=2)
	{
		a=1; b=1; c=3;
		while(1)
		{
			if(a==1&&b==1&&c==1)
			{
				count++;
				break;
			}
			if(!a||!b||!c)
			break;
			t=c;
			c=(a+b+c)%i;
			p=b;
			b=t;
			a=p;
		}
	}
	printf("%lld",i-2);
}
