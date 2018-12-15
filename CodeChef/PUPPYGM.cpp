#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int t,a,b;
	sc(t);
	while(t--)
	{
		sc(a); sc(b);
		if(a%2&&b%2)
		printf("Vanka\n");
		else
		printf("Tuzik\n");
	}
	return 0;
}
