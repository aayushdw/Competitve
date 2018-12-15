#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1550000
#define LIMIT 1550000
#define MOD 10000000000000000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
long long int primes[700];
long long int arr[LIMIT]={1};
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
int main()
{
	seive();
	int j=0,i,k;
	for(i=0;i<5000;i++)
	if(!t[i])
	primes[j++]=i;
	for(i=0;i<j;i++)
	{
		for(k=LIMIT-primes[i]-1;k>=0;k--)
		{
			arr[k+primes[i]]+=arr[k];
			arr[k+primes[i]]%=MOD;
		}
	}
	long long int count=0;
	for(i=1;i<LIMIT;i++)
	{
		if(!t[i])
		{
			count+=arr[i];
			count%=MOD;
		}
	}
	printf("%lld",count);
}
