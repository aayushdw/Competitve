#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define ll long long int
int main()
{
	ll a,b,c;
	sc(a); sc(b); sc(c);
	double x,y;
	x=(-b+sqrt(b*b-4*a*c))/(2.0*a);
	y=(-b-sqrt(b*b-4*a*c))/(2.0*a);
	if(x>y)
	printf("%0.9lf\n%0.9lf",x,y);
	else
	printf("%0.9lf\n%0.9lf",y,x);
	return 0;
}
