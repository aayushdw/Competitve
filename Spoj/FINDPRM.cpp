#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int numPrimes[MAX+1]={0,0};
void seive()
{
	int i=2,j;
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
int main()
{
	int i,test,n;
	seive();
	for(i=2;i<=MAX;i++)
	{
		if(!t[i])
		numPrimes[i]=numPrimes[i-1]+1;
		else
		numPrimes[i]=numPrimes[i-1];
	}
	sc(test);
	while(test--)
	{
		sc(n);
		printf("%d\n",numPrimes[n]-numPrimes[n/2]);
	}
	return 0;
}
