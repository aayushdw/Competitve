#include<stdio.h>
int check1(int a[])
{
	int i,j;
	for(i=0;i<6;i++)
	for(j=0;j<i;j++)
	if(a[i]==a[j])
	return 1;
	return 0;
}
int check(int a,int b,int c)
{
	int a1[6],a2[6],i;
	i=0;
	while(a)
	{
		a1[i]=a%10; a2[i]=b%10;
		a/=10; b/=10;
	}
	if(check1(a1)||check1(a2))
	return 0;
}
int main()
{
	long long int i,a,b,c,count=0;;
	for(i=1025986314;i<=1025986333;i++)
	{
		a=i/1000000;
		b=i%10000;
		c=(i%1000000)/10000;
		if(check(a,b,c))
		count++;
	}
	printf("%lld",count);
	return 0;
}
