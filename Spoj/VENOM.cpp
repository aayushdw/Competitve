#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%d",&x)
int getZero(int a,int b,int c)
{
	double p=(sqrt(b*b-4*a*c)-b)/(2*a);
	int r=ceil(p);
	return r;
}
int main()
{
	int t,H,h,p,a,b,c;
	sc(t);
	while(t--)
	{
		sc(H); sc(p); sc(h);
		if(H<=p)
		{
			printf("1\n");
			continue;
		}
		a=p; b=p-2*h; c=2*(h-H);
		//printf("%d %d %d == %d\n",a,b,c,getZero(a,b,c));
		printf("%d\n",2*getZero(a,b,c)-1);
	}
	return 0;
}
