#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 64000000
bool t[MAX]={1,1,0};
ll primes[3785100],count;
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



bool isSquare(ll p)
{
	double a=sqrt(p);
	ll q=(int)a;
	if(q*q==p)
	return true;
	return false;
}



ll powFact(ll n,ll p)
{
	ll c=0,q=p;
	while(n/q)
	{
		c+=n/q;
		q*=p;
	}
	return c;
}



ll powmod(ll a,ll b,ll MOD)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x%MOD;
}
