#include<stdio.h>
#define sc(x) scanf("%d",&x)
void print(int p)
{
	if(p==0)
	printf("4 * 4");
	if(p==1)
	printf("4 + 4");
	if(p==2)
	printf("4 - 4");
	if(p==3)
	printf("4 / 4");
	return;
}
int main()
{
	int t,n,i,j,p;
	int a[4]={16,8,0,1},b[4]={16,8,0,1};
	sc(t);
	while(t--)
	{
		sc(n);
		p=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(a[i]*b[j]==n)
			{
				p=1;
				break;
			}
			if(p)
			break;
		}
		if(p)
		{
			print(i); printf(" * "); print(j); printf(" = %d",n); printf("\n");
			continue;
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(a[i]+b[j]==n)
			{
				p=1;
				break;
			}
			if(p)
			break;
		}
		if(p)
		{
			print(i); printf(" + "); print(j); printf(" = %d",n); printf("\n");
			continue;
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			if(a[i]-b[j]==n)
			{
				p=1;
				break;
			}
			if(p)
			break;
		}
		if(p)
		{
			print(i); printf(" - "); print(j); printf(" = %d",n);
			printf("\n");
			continue;
		}
		if(!p)
		printf("no solution");
		printf("\n");
	}
	return 0;
}
