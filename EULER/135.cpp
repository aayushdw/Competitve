#include<stdio.h>
#define MAX 1000000
int count[MAX]={0};
int main()
{
	long long int a,d,i,p;
	p=(MAX+1)/4+1;
	for(d=1;d<=p;d++)
	{
		if(d%10000==0)
		printf("%d\n",d);
		for(a=d+1;a<4*d;a++)
		{
			if(4*a*d-a*a<MAX&&4*a*d-a*a>0)
			count[4*a*d-a*a]++;
		}
	}
	int c=0;	
	for(i=0;i<MAX;i++)
	if(count[i]==10)
	c++;
	printf("%d",c);
	return 0;
}
