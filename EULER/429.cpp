#include<stdio.h>
#include<math.h>
#include<bitset>
#define MAX 100000000
#define M 1000000009
typedef long long int ll;
using namespace std;
bitset<MAX> t;
ll primes[5761500],count;
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
ll mulmod(ll x, ll y, ll m) {
    ll w=x*y-m*(ll(double(x)*y/m+1e-3));
	while(w<0)
		w+=m;
	while(w>=m)
		w-=m;
	return w;
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
ll pow_in_fact(ll n,ll p)
{
	ll num=0,k=p;
	while(n/k)
	{
		num+=n/k;
		k*=p;
	}
	return num;
}
int main()
{
	seive();
	ll ans=1,i;
	for(i=0;i<count;i++)
	ans=mulmod(ans,1+modulo(primes[i],2*pow_in_fact(MAX,primes[i]),M),M);
	printf("%lld\n",ans);
}
