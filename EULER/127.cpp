#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define MAX 120000
using namespace std;
bool t[MAX]={1,1,0};
ll primes[11400],num,rad[MAX];
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
void pre()
{
	ll i,j;
	for(i=0;i<MAX;i++)
	rad[i]=1;
	for(i=0;i<num;i++)
	for(j=primes[i];j<MAX;j+=primes[i])
	rad[j]*=primes[i];
	return;
}

int main()
{
	ll a,b,c,ra,rb,rc,i,j,sum=0;
	seive();
	pre();
	for(i=1;i<MAX;i++)
	{
		c=i; rc=rad[c];
		for(j=1;j<(c+1)/2;j++)
		{
			a=j; b=c-j; ra=rad[a]; rb=rad[b];
			if(ra*rb*rc<c && __gcd(a,b)==1 && __gcd(a,c)==1 && __gcd(b,c)== 1)
			{
				//printf("%lld %lld %lld, %lld %lld %lld, %lld\n",a,b,c,ra,rb,rc,ra*rb*rc);
				sum+=c;
			}
		}
	}
	printf("%lld",sum);
	
}
