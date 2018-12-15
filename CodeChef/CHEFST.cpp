#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
#define MAX 50000
int main()
{
	ll a,b,t,m,max,min,lim;
	sc(t);
	while(t--)
	{
		sc(a); sc(b); sc(m);
		min=a<b?a:b;
		max=a>b?a:b;
		lim=m*(m+1)/2;
		if(lim>=min)
		printf("%lld\n",max-min);
		else
		printf("%lld\n",max+min-2*lim);
	}
	return 0;
}
