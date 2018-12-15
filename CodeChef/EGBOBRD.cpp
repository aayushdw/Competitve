#include<stdio.h>
int main()
{
	long long int t,n,p,sum,k,a;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld%lld",&n,&p);
		while(n--)
		{
			scanf("%lld",&a);
			sum+=a;
			if(sum%p)
			sum++;
		}
		k=sum/p+((sum%p)>0);
		printf("%lld\n",k);
	}
	return 0;
}
