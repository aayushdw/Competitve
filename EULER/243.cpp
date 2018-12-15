#include<stdio.h>
long long int phi(long long int n)
{
	long long int result=n,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		result-=result/i;
		while(n%i==0)
		n/=i;
	}
	if(n>1)
	result-=result/n;
	return result;
}
int main()
{
	long long int i=223092870*6,j;
	printf("%0.15lf\n",phi(i)*1.0/(i-1));
	printf("%0.15lf\n",15499/94744.0);
	printf("%lld\n",i);
	return 0;
}
