#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int t,n,p,i;
	sc(t);
	while(t--)
	{
		sc(n);
		if(n<7)
		{
			printf("-1\n");
			continue;
		}
		if(n==8)
		{
			printf("8\n");
			for(i=1;i<4;i++)
			printf("%d %d\n",i,i+1);
			printf("1 4\n");
			printf("4 5\n");
			printf("2 6\n");
			printf("3 7\n");
			printf("4 8\n");
			printf("1\n");
			continue;
		}
		printf("%d\n",n);
		for(i=1;i<n-1;i++)
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",1,n-1);
		printf("%d %d\n",1,n);
		printf("%d\n",(n-1)/4+1);
	}
	return 0;
}
