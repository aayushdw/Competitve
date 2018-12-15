#include<stdio.h>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define ll long long int
int main()
{
	ll n;
	sc(n);
	ll p=(n%2?1:2);
	pr(p);
}
