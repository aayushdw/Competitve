#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a<b)
	return gcd(b%a,a);
	if(a>=b)
	return gcd(a%b,b);
}
int main()
{
	ll t,x1,x2,y1,y2,a,b,i,k;
	sc(t);
	for(i=1;i<=t;i++)
	{
		sc(x1); sc(y1); sc(x2); sc(y2);
		if(x1==0&&y1==0)
		printf("Case %lld: 0\n",i);
		else
		{
			a=x1*(x2+1)+y1*(y2+1);
			b=(x1+y1)*(x2+y2+1);
			k=gcd(a,b);
			a/=k;
			b/=k;
			printf("Case %lld: %lld/%lld\n",i,a,b);
		}
	}
	return 0;
}
