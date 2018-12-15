#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int primes[785000];
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
int etf(int p)
{
	if(!t[p])
	return p-1;
	int i=0,e=1,c,k;
	while(p>1)
	{
		k=primes[i++];
		c=0;
		while(p%k==0)
		{
			p/=k;
			c++;
		}
		if(c)
		e*=pow(k,c-1)*(k-1);
	}
	return e;
}
int main()
{
	int i,j=0,test,p,k;
	seive();
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	sc(test);
	while(test--)
	{
		k=etf(test);
	}
	return 0;
}
