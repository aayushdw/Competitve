#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 64000000
bool t[MAX]={1,1,0},isPrimePow[MAX]={0};
ll primes[3785100], div[MAX];
void seive()
{
	ll i=2,j;
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
bool isSquare(ll p)
{
	double a=sqrt(p);
	ll q=(int)a;
	if(q*q==p)
	return true;
	return false;
}
int main()
{
	seive();
	long long int i,count=0,j,p,q;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[count++]=i;
	for(j=0;j<MAX;j++)
	div[j]=1;
	for(i=0;i<count;i++)
	{
		p=primes[i]; q=primes[i]*primes[i];
		while(p<MAX)
		{
			div[p]=div[p/primes[i]]+q;
			isPrimePow[p]=true;
			p*=primes[i];
			q*=primes[i]*primes[i];
		}
	}
	for(i=0;i<count;i++)
	{
		p=primes[i];
		while(p<MAX)
		{
			q=p;
			for(q=2*p;q<MAX;q+=p)
			{
				if(isPrimePow[q])
				continue;
				div[q]/=div[p/primes[i]];
				div[q]*=div[p];
			}
			p*=primes[i];
		}
	}
	ll sum=0;
	for(i=1;i<MAX;i++)
	if(isSquare(div[i]))
	sum+=i;
	printf("%lld",sum);
}
