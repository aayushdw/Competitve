#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld",x)
#define ll long long int
int main()
{
	ll a,b,t,p;
	sc(a); sc(b);
	pr(a); pr(b);
	for(ll i=0;i<100;i++)
	{
		t=(4*b+a)%7;
		pr(t);
		a=b;
		b=t;
	}
}
