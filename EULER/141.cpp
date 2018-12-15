#include<stdio.h>
#include<bitset>
#include<math.h>
#define ll long long int
#define MAX 1000000000000
#define LIM 1000000
using namespace std;
bitset<LIM> t;
ll isSquare(ll p)
{
	if(p<0)
	printf("OVERFLOW\n");
	double a=sqrt(p);
	ll q=(ll)a;
	if(q*q==p)
	return q;
	return 0;
}
ll gcd(ll a,ll b)
{
	if(!a)
	return b;
	return gcd(b%a,a);
}
int main()
{
	ll a,b,p,count=0;
	for(a=1;a*a*a<MAX;a++)
	for(b=1;b<a;b++)
	{
		if(gcd(a,b)!=1)
		continue;
		for(p=1;a*a*a*b*p*p+p*b*b<MAX;p++)
		if(isSquare(a*a*a*b*p*p+p*b*b))
		t[isSquare(a*a*a*b*p*p+p*b*b)]=true;
	}
	for(ll i=0;i*i<MAX;i++)
	if(t[i])
	count+=i*i;
	printf("%lld\n",count);
}






