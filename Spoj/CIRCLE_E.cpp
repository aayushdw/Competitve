#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lf",&x)
int main()
{
	int t;
	double a,b,c,r;
	scanf("%d",&t);
	while(t--)
	{
		sc(a); sc(b); sc(c);
		a=1.0/a; b=1.0/b; c=1.0/c;
		r=a+b+c+2*sqrt(a*b+b*c+a*c);
		r=1.0/r;
		printf("%lf\n",r);
	}
	return 0;
}
