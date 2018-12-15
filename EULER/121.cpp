#include<stdio.h>
#define ll long long int
#define N 15
ll num=0;
bool nthBit(ll num,ll bit)
{
	return (num>>bit)&1;
}
int check(ll a[])
{
	ll i,m=1,s=0;
	
	for(i=0;i<N;i++)
	{
		if(!a[i])
		m*=(i+1);
		s+=a[i];
	}
	if(s>=(N+1)/2)
	{
		num+=m;
		return 1;
	}
	return 0;
}
int main()
{
	ll i,a[N];
	for(i=(2<<(N-1));i<(2<<(N));i++)
	{
		//printf("%lld->\t",i);
		for(ll j=0;j<N;j++)
		a[j]=nthBit(i,j);
		check(a);
		/*if(check(a))
		{
			for(ll j=0;j<N;j++)
			printf("%lld ",a[j]);
			printf("\t -> %lld\n",num);
		}*/
	}
	printf("%lld",num);
}
