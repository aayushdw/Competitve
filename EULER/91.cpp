#include<stdio.h>
#define MAX 50
int d(int a,int b,int x,int y)
{
	return (a-x)*(a-x)+(b-y)*(b-y);
}
int main()
{
	int a,b,x,y,d1,d2,d3,count=0;
	for(a=0;a<=MAX;a++)
	{
		for(b=0;b<=MAX;b++)
		{
			if(a==0&&b==0)
			continue;
			for(x=0;x<=MAX;x++)
			{
				for(y=0;y<=MAX;y++)
				{
					if(x==0&&y==0)
					continue;
					if(a==x&&b==y)
					continue;
					d1=d(0,0,a,b);
					d2=d(0,0,x,y);
					d3=d(a,b,x,y);
					if(d1+d2==d3||d1+d3==d2||d2+d3==d1)
					{
					printf("(%d,%d) (%d,%d)\n",a,b,x,y);
					count++;}
				}
			}
		}
	}
	printf("%d",count/2);
	return 0;
}
