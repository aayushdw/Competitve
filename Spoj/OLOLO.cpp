#include<stdio.h>
#define sc(x) scanf("%d",&x)
int bitXOR(int a,int b)
{
	int x=(a&b);
	int y=(~a&~b);
	return (~x&~y);
}
int main()
{
	int n,a=0,i;
	sc(n);
	while(n--)
	{
		sc(a);
		i=bitXOR(i,a);
	}
	printf("%d",i);
	return 0;
}
