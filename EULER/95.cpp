#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000
bool t[MAX]={1,1,0};
int primes[78500]={0};
int arr[20000];
void seive()
{
	int i,j;
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
int sum_div(int p)
{
	int sum=1,i=0,c,k;
	while(p>1)
	{
		c=1; k=1;
		while(p%primes[i]==0)
		{
			p/=primes[i];
			c*=primes[i];
			k+=c;
		}
		sum*=k;
		i++;
	}
	return sum;
}
int check(int p)
{
	int k=arr[p-1],i;
	for(i=p-2;i>=0;i--)
	if(k==arr[i])
	return 1;
	return 0;
}
int amicable_count(int p)
{
	int count=0,k=p;
	while(1)
	{
		k=sum_div(k)-k;
		arr[count]=k;
		printf("%d ",k);
		count++;
		//printf("%d\n",k);
		if(k==1||k>MAX||check(count))
		return 0;
		if(k==p)
		return count;
	}
	printf("\n");
}
int main()
{
	int i,j=0,num,k;
	seive();
	for(i=0;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	int m=0;
	for(i=2;i<MAX;i++)
	{
		if(i%100000==0)
		printf("%d %d %d\n",i,num,m);
		k=amicable_count(i);
		//printf("%d %d\n",i,k);
		if(k>m)
		{
			m=k;
			num=i;
		}
	}
	printf("%d %d",num,m);
	return 0;
}
