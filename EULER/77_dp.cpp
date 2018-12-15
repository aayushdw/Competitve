#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000000
#define LIMIT 5000
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
int main()
{
	seive();
	int i,j=0,target=10;
	for(i=0;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	int arr[105]={1};
	for(i=0;i<40;i++)
	{
		for(j=primes[i];j<=target;j++)
		{
			arr[j]+=arr[j-primes[i]];
		}
	}
	for(i=1;i<=target;i++)
	{
		printf("%d %d\n",i,arr[i]);
		/*if(arr[i]>LIMIT)
		{
			printf("%d",i);
			return 0;
		}*/
	}
	return 0;
}
