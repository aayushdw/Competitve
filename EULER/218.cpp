#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 1e8
ll count=0,total=0; 
bool check(ll a,ll b)
{
	if(a%2==0)
	a/=2;
	else if(b%2==0)
	b/=2;
	else
	return 0;
	ll p=((a%6)*(b%6))%6;
	ll q=((a%28)*(b%28))%28;
	if(p||q)
	return 0;
	return 1;
}
bool isSquare(ll p)
{
	double q=sqrt(p);
	ll a=(ll)q;
	if(a*a==p)
	return 1;
	return 0;
}
void primitivePythagoreanTriplets(ll a,ll b,ll c)
{
	if(c>MAX)
	return;
	//printf("%lld %lld %lld\n",a,b,c);
	primitivePythagoreanTriplets(a+2*b+2*c,2*a+b+2*c,2*a+2*b+3*c);
	primitivePythagoreanTriplets(a-2*b+2*c,2*a-b+2*c,2*a-2*b+3*c);
	primitivePythagoreanTriplets(-a+2*b+2*c,-2*a+b+2*c,-2*a+2*b+3*c);
	if(isSquare(c))
	{
		total++;
		if(check(a,b))
		count++;
	}
}
int main()
{
	ll a=3,b=4,c=5;
	primitivePythagoreanTriplets(a,b,c);
	printf("%lld %lld",count,total);
}
