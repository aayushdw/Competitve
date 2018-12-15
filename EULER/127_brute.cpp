#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define MAX 1000
using namespace std;
bool t[MAX]={1,1,0};
ll primes[11400],num;
vector<pair<ll,ll> > v;
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
	num=j;
	return;
}
ll rad(ll n)
{
	ll r=1, i=0,p,c;
	while(n>1)
	{
		p=primes[i];
		c=0;
		while(n%p==0)
		{
			n/=p;
			c++;
		}
		if(c)
		r*=p;
		i++;
	}
	return r;
}
int main()
{
	ll a,b,c,count=0,sum=0;
	seive();
	//printf("%lld\n",rad(6));
	for(c=1;c<MAX;c++)
	{
		for(a=1;a<(c+1)/2;a++)
		{
			b=c-a;
			if(__gcd(a,b)==1 && __gcd(b,c)==1 && __gcd(a,c)==1 && rad(a*b*c)<c)
			{
				printf("%lld %lld %lld\n",a,b,c);
				count++;
				sum+=c;
			}
		}
	}
	printf("%lld %lld",count,sum);
}
