#include<stdio.h>
#define MAX 10
#define ll long long int
ll C(ll n,ll r)
{
	if(r==0||n==r)
	return 1;
	return C(n-1,r)+C(n-1,r-1);
}
int main()
{
	ll i,sum=0;
	//printf("%lld",C(108,8));
	for(i=1;i<=MAX;i++)
	sum+=C(i+8,8)+C(i+9,9)-10;
	printf("%lld",sum);
}
