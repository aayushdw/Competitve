#include<stdio.h>
#define ll long long int
#define MAX 1000000
ll mdrs[MAX]={0,1};
ll max(ll a,ll b)
{return a>b?a:b;}
ll getSum(ll p)
{
	ll sum=0;
	while(p)
	{
		sum+=p%10;
		p/=10;
	}
	if(sum>=10)
	sum=getSum(sum);
	return sum;
}
int main()
{
	ll i,j,sum=0;
	for(i=2;i<MAX;i++)
	{
		for(j=2;j*j<=i;j++)
			if(i%j==0)
				mdrs[i]=max(mdrs[i],mdrs[j]+mdrs[i/j]);
		mdrs[i]=max(mdrs[i],getSum(i));
	}
	for(i=2;i<MAX;i++)
		sum+=mdrs[i];
	printf("%lld\n",sum);
}
