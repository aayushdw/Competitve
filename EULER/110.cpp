#include<stdio.h>
#include<math.h>
#include<limits.h>
#define ll long long int
#define MAX 4000000
#define LIM log10(MAX)
ll primes[14];
double max=INT_MAX;
void solve(double p, ll ex,ll n,ll q,ll idx)
{
	for(ll i=1;i<=ex;i++)
	{
		if(n==43)
		printf("%lf %lld\n",p,q);
		if(p>MAX)
		return;
		if(q*(2*i+1)>MAX)
		{
			double a=p+i*log10(n);
			if(a<max)
			max=a;
			return;
		}
		solve(p+i*log10(n),i,primes[idx+1],q*(2*i+1),idx+1);
	}
}
int main()
{
	ll i,j,count=0;
	for(i=2;count<14;i++)
	{
		for(j=2;j*j<=i;j++)
		if(i%j==0)
		break;
		if(j*j>i)
		primes[count++]=i;
	}
	double p=0;
	for(j=0;j<count;j++)
	p+=log10(primes[j]);
	printf("%lf\n",p);
	solve(0,MAX/2,2,1,0);
	printf("%lf %lld\n",max,exp(max));
}
