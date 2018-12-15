#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000000+100
#define sc(x) scanf("%d",&x)
#define ll long long int
bool t[MAX]={1,1,0};
ll primes[78500],count,cube[MAX];
void seive()
{
	int i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}
bool isCube(ll p)
{
	ll root(round(cbrt(p)));
	return root*root*root==p;
}
int main()
{
	seive();
	ll i,j=0;
	for(i=0;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	printf("%lld\n",j);
	count=0;
	for(i=0;i<MAX;i++)
	cube[i]=i*i*i;
	for(i=0;primes[i]<1000000;i++)
	{
		for(j=1;j<1000;j++)
		if(isCube(primes[i]+cube[j]))
		{
			count++;
			//printf("%lld %lld\n",primes[i],cube[j]);
		}
	}
	printf("%lld",count);
}
