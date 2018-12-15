#include<stdio.h>
#define MAX 100
int numWays(int target,int min)
{
	int sum=0,i;
	if(min==MAX-1)
	return 1;
	for(i=min;i<MAX;i++)
	{
		if(target==i) sum+=1;
		if(target>i)
		sum+=numWays(target-i,i);
	}
	return sum;
}
int main()
{
	int i,sum=0;
	for(i=1;i<MAX;i++)
	{
		printf("%d\n",i);
	sum+=numWays(MAX-i,i);
	}
	printf("%d",sum);
}
