#include<stdio.h>
int main()
{
	long long int t=21,b=15,ti,bi;
	while(t<=1000000000000)
	{
		ti=3*t+4*b-3;
		bi=3*b+2*t-2;
		t=ti; b=bi;
		printf("%lld %lld\n",b,t);
	}
	return 0;
}
