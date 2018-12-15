#include<stdio.h>
#define ll long long int
#include<map>
using namespace std;
map<ll,ll> X2;
ll F2(ll n)
{
	return (n-1)*n/2;
}
ll R2(ll n)
{
	if(n==1)
	return 0;
	if(X2[n])
	return X2[n];
	ll sum=F2(n), m=2;
	while(1)
	{
		ll x=n/m;
		ll nxt=n/x;
		if(nxt>=n)
		return X2[n]=sum-(n-m+1)*R2(n/m);
		sum-=(nxt-m+1)*R2(n/m);
		m=nxt+1;
	}
}
int main()
{
	ll n=100000000;
	printf("%lld",(n*(n+1)/2-R2(n)-1)*6);
}
