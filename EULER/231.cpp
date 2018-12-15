#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 20000000
bool t[MAX]={1,1,0},isPrimePow[MAX]={0};
ll primes[1270700], div[MAX], powFact[1270700]={0},count;
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
ll pow_in_fact(ll n,ll p)
{
	ll count=0,q=p;
	while(n/q)
	{
		count+=n/q;
		q*=p;
	}
	return count;
}
void solve(ll p,ll q)
{
	ll j;
	for(j=0;j<count;j++)
	powFact[j]+=q*pow_in_fact(p,primes[j]);
}
int main()
{
	seive();
	solve(20000000,1);
	solve(15000000,-1);
	solve(5000000,-1);
	ll sum=0;
	for(ll i=0;i<count;i++)
	sum+=primes[i]*powFact[i];
	printf("%lld",sum);
}
