#include<stdio.h>
#define ll long long int
bool isInc(ll a[],ll sz)
{
	ll i;
	for(i=0;i<sz-1;i++)
	if(a[i+1]<a[i])
	return false;
	return true;
}
bool isDec(ll a[],ll sz)
{
	ll i;
	for(i=0;i<sz-1;i++)
	if(a[i+1]>a[i])
	return false;
	return true;
}
bool check(ll p)
{
	ll a[20],i=0;
	while(p)
	{
		a[i++]=p%10;
		p/=10;
	}
	return isDec(a,i)||isInc(a,i);
}
int main()
{
	ll i,count=0;
	for(i=1;;i++)
	{
		if(!check(i))
		count++;
		if(count*1.0/i>=0.99)
		{
			printf("%lld",i);
			return 0;
		}
	}
}

