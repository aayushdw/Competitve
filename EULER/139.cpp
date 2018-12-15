#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ll long long int
#define MAX 100
using namespace std;
ll gcd(ll a,ll b)
{
	ll c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	ll i,j,count=0,a,b,c,d,p;
	for(i=2;i*i<MAX;i++)
	for(j=1;j<i;j++)
	{
		if((i+j)%2==1 && gcd(i,j)==1)
		{
		a=i*i-j*j;
		b=2*i*j;
		c=i*i+j*j;
		//printf("%lld %lld %lld\n",a,b,c);
		p=a+b+c;
		d=(a>b)?a-b:b-a;
		if(c%d==0)
		count+=MAX/p;
		}
	}
	printf("%lld",count);
}
