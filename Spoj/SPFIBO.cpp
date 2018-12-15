#include<stdio.h>
#define MAX 10000000000000000
typedef long long int ll;
ll res=0,fib[100]={1,1},count[100]={0,1,2};
void fun(ll a)
{
	if(a==0)
	return;
	a--;
	ll i=1,k;
	while(1)
	{
		k=fib[i+1]-1;
		if(k>a)
		{
			res+=count[i-1];
			res+=a-fib[i]+1;
			fun(a-fib[i]+1);
			return;
		}
		i++;
	}
}
void f(ll b,ll p,ll n)
{
	int i;
	for(i=0;i<b;i++)
	{
		if(fib[p-i]<=n)
		{
			n-=fib[p-i];
			res++;
		}
	}
}
int main()
{
	ll n,i=2,k,a,b;
	while(fib[i-1]<MAX)
	{
		fib[i]=fib[i-1]+fib[i-2];
		i++;
	}
	for(i=3;i<70;i++)
	count[i]=count[i-1]+fib[i-1]+count[i-2];
	scanf("%lld",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	n--;
	i=2;
	while(1)
	{
		k=i*fib[i-1];
		if(k<n)
		{
			n-=k;
			i++;
			continue;
		}
		if(n==k)
		{
			printf("%lld",count[i]);
			return 0;
		}
		else
		{
			a=n/i;
			b=n%i;
			ll p=fib[i]+a;
			res+=count[i-1]+a;
			fun(a);
			f(b,i,p);
			printf("%lld",res);
			return 0;
		}
	}
	return 0;
}
