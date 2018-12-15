#include<stdio.h>
#include<math.h>
#define ll long long int
#define N 20
#define D 12
#define K 10
#define T 70
ll c[N+1][N+1]={0};
ll C(ll n,ll r)
{
	if(c[n][r])
	return c[n][r];
	if(r==0||n==r)
	{
		c[n][r]=1;
		return c[n][r];
	}
	return C(n-1,r-1)+C(n-1,r);
}
ll power(ll a,ll b)
{
	ll p=1;
	for(ll i=1;i<=b;i++)
	p*=a;
	return p;
}
ll f(ll n,ll d,ll k,ll t)
{
	if(k==0&&t!=0)
	{
		/*printf("f(%lld,%lld,%lld,%lld)=",n,d,k,t);
		printf("0\n");*/
		return 0;
	}
	if(n==0&&d==0&&k==0&&t==0)
	return 1;
	if(d==0)
	{
		/*printf("f(%lld,%lld,%lld,%lld)=",n,d,k,t);
		printf("0\n");*/
		return 0;
	}
	if(k==0&&t==0)
	{
		/*printf("f(%lld,%lld,%lld,%lld)=",n,d,k,t);
		printf("%lld\n",power(d,n));*/
		return power(d,n);
	}
	ll i,sum=0;
	for(i=0;t-d*i>=0&&k-i>=0;i++)
	sum+=C(n,i)*f(n-i,d-1,k-i,t-d*i);
	i--;
	if(t-d*i==0 && k-i==0)
	{
		i++;
		while(n-i>=0)
		{
			sum+=C(n,i)*f(n-i,d-1,0,0);
			i++;
		}
	}
	/*printf("f(%lld,%lld,%lld,%lld)=",n,d,k,t);
	printf("%lld\n",sum);*/
	return sum;
}
int main()
{
	printf("%lld",f(N,D,K,T));
}
