#include<stdio.h>
#include<math.h>
#include<bitset>
#define ll long long int
#define MAX 100000000
using namespace std;
bitset<MAX> t;
ll primes[5761500],count;
void seive()
{
	ll i=2,j;
	t[0]=t[1]=1;
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
	for(i=5;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	count=j;
	return;
}
ll modulo(ll a,ll b,ll MOD)
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
ll modInv(ll a,ll m)
{
	return modulo(a,m-2,m);
}
int main()
{
	seive();
	ll sum=0,a,b,p,i,c;
	for(i=0;i<count;i++)
	{
		p=primes[i];
		c=b=p-1;
		for(ll j=1;j<=4;j++)
		{
			a=modInv(p-j,p);
			b*=a;
			b%=p;
			c+=b;
			c%=p;
		}
		sum+=c;
	}
	printf("%lld",sum);
}
