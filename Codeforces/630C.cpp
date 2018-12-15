#include<stdio.h>
int main()
{
	long long int x,i,a[60],sum=0;;
	scanf("%d",&x);
	a[1]=2;
	for(i=2;i<60;i++)
	{
		a[i]=a[i-1]*2;
		//printf("%I64d\n",a[i]);
	}
	for(i=1;i<=x;i++)
	sum+=a[i];
	printf("%I64d",sum);
}
