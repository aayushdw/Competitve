#include<stdio.h>
#include<math.h>
#define ll long long int
int main()
{
	ll sum=0;
	for(int i=2;i<=15;i++)
	{
		double p=1;
		for(int j=1;j<=i;j++)
		p*=pow(2.0*j/(i+1),j);
		sum+=(ll)p;
	}
	printf("%lld",sum);
}
