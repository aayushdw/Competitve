#include<stdio.h>
#define sc(x) scanf("%lld",&x)
typedef long long int ll;
ll pow(ll a,ll b)
{
	if(a==0)
	return 0;
	ll out=1;
	while(b--)
	out*=a;
	return out;
}
int main()
{
	ll t,n;
	sc(t);
	while(t--)
	{
		sc(n);
		printf("%lld\n",pow(3,n)-1);
	}
	return 0;
}
