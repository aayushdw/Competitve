#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000000
#define MOD 1000000007
#define sc(x) scanf("%lld",&x)
bool t[MAX]={1,1,0};
long long int numPrimes[MAX+1]={0,0};
void seive()
{
	long long int i=2,j;
	while(i*i<=MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<=MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}
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
long long int modExpo(long long int a,long long int b)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x*=y;
			x%=MOD;
		}
		y*=y;
		y%=MOD;
		b/=2;
	}
	return x;
}
int main()
{
	long long int test,i,n,f,k;
	long long int r;
	sc(test);
	while(test--)
	{
		sc(n);
		if(n==30)
		printf("%lld\n",phi(30)*phi(30));
		else
		printf("%lld\n",phi(n));
	}
	return 0;
}
