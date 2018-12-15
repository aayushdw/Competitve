#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 100
#define NUM 1000000000
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int pr[50];
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
	int i,j=0,k,count=0,p,q;
	for(i=2;i<MAX;i++)
	if(!t[i])
	pr[j++]=i;
	for(i=2;i<NUM;i++)
	{
		if(i%10000000==0)
		printf("%d\n",i);
		q=i;
		for(k=0;k<j;k++)
		{
			p=pr[k];
			while(q%p==0)
			q/=p;
		}
		if(q==1)
		count++;
	}
	printf("%d",count);
}
