#include<stdio.h>
#define sc(x) scanf("%d",&x)
int phi(int n)
{
	int result=n,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		result-=result/i;
		while(n%i==0)
		n/=i;
		//printf("i=%d result=%d n=%d\n",i,result,n);
	}
	if(n>1)
	result-=result/n;
	return result;
}
int main()
{
	int t,p;
	sc(t);
	while(t--)
	{
		sc(p);
		printf("%d\n",phi(p));
	}
	return 0;
}
