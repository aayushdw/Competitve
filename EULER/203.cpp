#include<stdio.h>
#include<math.h>
#include<set>
#define ll long long int
#define MAX 60
using namespace std;
bool t[MAX]={1,1,0};
ll primes[25],num;
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
bool isSquareFree(ll n,ll r)
{
	num=1;
	for(ll i=0;primes[i]<=n;i++)
	if(pow_in_fact(n,primes[i])-pow_in_fact(r,primes[i])-pow_in_fact(n-r,primes[i])>1)
	return false;
	else
	num*=pow(primes[i],pow_in_fact(n,primes[i])-pow_in_fact(r,primes[i])-pow_in_fact(n-r,primes[i]));
	return true;
}
int main()
{
	set<ll> s;
	seive();
	for(ll n=1;n<51;n++)
	{
		for(ll r=0;r<=(n+1)/2;r++)
		if(isSquareFree(n,r))
		s.insert(num);
	}
	ll sum=0;
	typeof(s.begin()) it;
	for(it=s.begin();it!=s.end();it++)
	sum+=*it;
	printf("%lld ",sum);
}
