#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 10000000
bool t[MAX]={1,1,0};
ll primes[664600],count;
void seive()
{
	ll i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	j=0;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	count=j;
	return;
}
ll intlog(ll base, ll x)
{
	return (ll)(log(x)/log(base));
}
ll solve(ll a,ll b,ll M)
{
	if(a*b>M)
	return 0;
	ll max=0,n=a;
	while(n*b<=M)
	{
		if(pow(b,intlog(b,M/n))*n>max)
		max=pow(b,intlog(b,M/n))*n;
		n*=a;
	}
	return max;
}
int main()
{
	seive();
	ll i,j,p,sum=0;
	for(i=0;i<count;i++)
	for(j=i+1;primes[i]*primes[j]<MAX&&j<count;j++)
	sum+=solve(primes[i],primes[j],MAX);
	printf("%lld",sum);
}
