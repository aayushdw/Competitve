#include<stdio.h>
int check(int p)
{
	int a[10]={0},i;
	while(p)
	{
		a[p%10]++;
		p/=10;
	}
	for(i=0;i<10;i++)
	if(a[i]!=1)
	return 0;
	return 1;
}
void foo(int p)
{
	int a[10],i,k;
	for(i=0;i<10;i++)
	{
		a[i]=p%10;
		if(a[i]==0)
		a[i]=10;
		p/=10;
	}
	k=a[0]+a[5]+a[6];
	for(i=1;i<4;i++)
	{
		if(a[i]+a[i+5]+a[i+6]!=k)
		return;
	}
	int m=a[0];
	for(i=1;i<5;i++)
	if(m>a[i])
	m=a[i];
	if(a[4]+a[9]+a[5]!=k)
	return;
	printf("(%d %d %d),",a[0],a[5],a[6]);
	for(i=1;i<4;i++)
	printf("(%d %d %d),",a[i],a[i+5],a[i+6]);
	printf("(%d %d %d)   %d\n",a[4],a[9],a[5],m);
	return;
}
int main()
{
	long long int i;
	int a,b,c;
	for(i=1000000000;i<=9999999999;i++)
	{
		if((i-1000000000)%1000000000==0)
		printf("%lld\n",i);
		if(!check(i))
		continue;
		foo(i);
	}
	return 0;
}
