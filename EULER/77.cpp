#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int primes[785];
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
	int i,j=0,k;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	int num[100]={0};
	for(i=0;i<100;i++)
	{
		for(j=2;j<i;j++)
		{
			k=i-j;
			if(k<=j)
			{
				if(!t[k]&&!t[j])
				num[i]++;
			}
			if(k>=j)
			{
				if(!t[j])
				num[i]+=num[k];
			}
		}
		printf("%d %d\n",i,num[i]);
	}
	return 0;
	
}
