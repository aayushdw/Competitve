#include<stdio.h>
#define MAX 100000
#define ll long long int
ll f[MAX]={0};
int main()
{
	ll i;
	for(i=0;i<2000;i++)
	f[i]=1;
	for(;i<20000;i++)
	{
		f[i]=f[i-2000]+f[i-1999];
		if(f[i]!=f[i-1])
		printf("%lld %lld\n",i,f[i]);
	}
}
