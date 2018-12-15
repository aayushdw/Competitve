#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 32000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int primes[10000];
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
	int i,j=0,test,n,count;
	for(i=0;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	
	sc(test);
	while(test--)
	{
		sc(n);
		count=0;
		for(i=0;primes[i]<=n/2;i++)
		if(!t[n-primes[i]])
		count++;
		printf("%d has %d representation(s)\n",n,count);
		for(i=0;primes[i]<=n/2;i++)
		if(!t[n-primes[i]])
		printf("%d+%d\n",primes[i],n-primes[i]);
		printf("\n");
	}
	return 0;
}




