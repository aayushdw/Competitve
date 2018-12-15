#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define scll(x) scanf("%lf",&x)
#define ll long double
int main()
{
	ll n,i,sum=0,t,a,b;
	scll(t);
	printf("%f\n",t);
	while(t--)
	{
		scll(n);
		sum=0;
		a=n;
		printf("%llf\n",n);
		for(i=2;a>=ceil(sqrt(n));i++)
		{
			a=ceil(n/(i+1));
			b=ceil(n/i);
			sum+=(i-1)*(b*(b+1)- a*(a+1))/2;
			if(sum<0)
			printf("ERROR");
			printf("%lld %lld %lld\n",i,a,b);
		}
		for(;a>0;a--)
		sum+=a*(ceil(n/a)-1);
		printf("%llf\n",sum);
	}
	return 0;
}
