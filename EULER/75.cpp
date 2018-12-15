#include<stdio.h>
#include<math.h>
#define MAX 1500000
int a[MAX+1]={0};
long long  int check(long long int p)
{
	long long int s=sqrt(p);
	if(s*s==p)
	return 1;
	return 0;
}
int main()
{
	long long int i,j,p=MAX/2,k;
	for(i=1;i<=p;i++)
	{
		//if(i%1000==0)
		printf("%d\n",i);
		for(j=i+1;j<=p;j++)
		{
			k=i*i+j*j;
			if(k<0)
			printf("%d\n",k);
			k=check(k);
			if(k)
			{
			//printf("%d %d %d\n",i,j,(int)sqrt(i*i+j*j));
			a[i+j+k]++;}
		}
	}
	int count=0;
	for(i=0;i<=MAX;i++)
	if(a[i]==1)
	{
	printf("%d\n",i);
	count++;}
	printf("%d",count);
	return 0;
}
