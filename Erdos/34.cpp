#include<stdio.h>
#include<bitset>
#define scll(x) scanf("%lld",&x)
#define ll long long int
#define MAX 10000000
#define MOD 1000000009
using namespace std;
bitset<MAX> t;
int primes[5761460];
void seive()
{
	int i=2,j;
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
			t.set(i*j);
			j++;
		}
		i++;
	}
	return;
}
ll p_in_n(ll p,ll n)
{
	ll e=p,exp=0;
	while(n/e)
	{
		exp+=n/e;
		e*=p;
	}
	return exp;
}
int main()
{
	seive();
	ll n,i,j=0,count,p;
	for(i=3;i<100;i++)
	if(!t[i])
	printf("%lld\n",i);
}
