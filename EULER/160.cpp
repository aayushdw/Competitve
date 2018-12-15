#include<stdio.h>
#include<math.h>
#include<bitset>
#define ll long long int
#define MAX 1000
#define M 100000
using namespace std;
bitset<MAX> t;
ll primes[40000],count;
void seive()
{
	t[0]=t[1]=1;
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
ll powFact(ll n,ll p)
{
	ll k=p,ans=0;
	while(n/k)
	{
		ans+=n/k;
		k*=p;
	}
	return ans;
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
int main()
{
	seive();
	ll f=1,i;
	f=powFact(MAX,2)-powFact(MAX,5);
	f=modulo(2,f,M);
	f*=modulo(3,powFact(MAX,3),M);
	f%=M;
	for(i=3;i<count;i++)
	{
		f*=modulo(primes[i],powFact(MAX,primes[i]),M);
		f%=M;
	}
	printf("%lld\n",f);
	printf("%lld",modulo(16864,10,M));
}
