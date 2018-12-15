#include<stdio.h>
#define MAX 50000000
int arr[MAX]={0};
int primes[1000]={2};
int check_prime(int p)
{
	int i;
	for(i=3;i*i<=p;i+=2)
	if(p%i==0)
	return 0;
	return 1;
}
int main()
{
	int i,j,k,count=0,a;
	for(i=3;i<7500;i+=2)
	if(check_prime(i))
	primes[j++]=i;
	for(i=0;;i++)
	{
		if(primes[i]*primes[i]>=MAX)
		break;
		for(j=0;;j++)
		{
			if(primes[j]*primes[j]*primes[j]>=MAX)
			break;
			for(k=0;;k++)
			{
				if(primes[k]*primes[k]*primes[k]*primes[k]>=MAX)
				break;
				a=primes[i]*primes[i]+primes[j]*primes[j]*primes[j]+primes[k]*primes[k]*primes[k]*primes[k];
				if(a<MAX)
				arr[a]++;
			}
		}
	}
	for(i=0;i<MAX;i++)
	if(arr[i])
	count++;
	printf("%d",count);
}
