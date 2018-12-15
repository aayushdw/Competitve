#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX 1000000
bool t[MAX+5]={1,1,0};
int prime[MAX/10];
void make_prime()
{
	int i=2,u=MAX+4,j;
	while(i*i<=u)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<=u)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}
long long int out(int i)
{
	long long int a=prime[i], b=prime[i+1],len=0;
	while(a)
	{
		a/=10;
		len++;
	}
	long long int add=pow(10,len);
	long long int p=add+prime[i];
	while(1)
	{
		if(p%b==0)
		return p;
		p+=add;
	}
}
int main()
{
	make_prime();
	long long int i,j=0,u=MAX+4,k;
	for(i=0;i<=u;i++)
	{
		if(!t[i])
		prime[j++]=i;
	}
	long long int index=j-1; 
	long long int sum=0;
	for(i=2;i<index;i++)
	{
		if(i%1000==0)
		printf("%lld\n",i);
		k=out(i);
		//printf("%lld %lld %lld\n",prime[i],prime[i+1],k);
		if(k<0)
		{
			printf("abort");
			return 0;
		}
		sum+=k;
	}
	printf("%lld",sum);
	return 0;
}
