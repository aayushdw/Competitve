#include<stdio.h>
#define ll long long int
#define sc(x) scanf("%lld",&x)
#define MOD 1000000007
#define MAX 1000005
ll fib[MAX]={1,1};
ll binary(ll p)
{
	ll count=0;
	while(p)
	{
		if(p%2)
		count++;
		p/=2;
	}
	return count;
}
int main()
{
	ll t,i,k,n,p;
	for(i=2;i<MAX;i++)
	fib[i]=(fib[i-1]+fib[i-2])%MOD;
	sc(t);
	while(t--)
	{
		sc(n); sc(p);
		k=binary(fib[n]);
		if(k==p)
		printf("CORRECT\n");
		else
		printf("INCORRECT\n");
	}
	return 0;
}
