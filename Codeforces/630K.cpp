#include<stdio.h>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define ll long long int
int main()
{
	ll n,p;
	sc(n);
	p=n;
	p+=n/6;
	p+=n/10;
	p+=n/14;
	p+=n/15;
	p+=n/21;
	p+=n/35;
	p-=n/2;
	p-=n/3;
	p-=n/5;
	p-=n/7;
	pr(p);
	return 0;
}
