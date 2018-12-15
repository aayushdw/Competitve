#include<stdio.h>
#define MAX 100
#define ll long long int
ll count=0;
void primitivePythagoreanTriplets(ll a,ll b,ll c)
{
	if(c>MAX)
	return;
	//printf("%lld %lld %lld\n",a,b,c);
	primitivePythagoreanTriplets(a+2*b+2*c,2*a+b+2*c,2*a+2*b+3*c);
	primitivePythagoreanTriplets(a-2*b+2*c,2*a-b+2*c,2*a-2*b+3*c);
	primitivePythagoreanTriplets(-a+2*b+2*c,-2*a+b+2*c,-2*a+2*b+3*c);
	count++;
}
int main()
{
	primitivePythagoreanTriplets(3ll,4ll,5ll);
	printf("%lld",count);
}
