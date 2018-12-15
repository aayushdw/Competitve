#include<stdio.h>
#define ll long long int
#define MOD 1000000007
#define sc(x) scanf("%lld",&x)
#define MAX 100000+5
ll power(ll a,ll b)
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
ll solve(ll a,ll b,ll k)
{
	ll i,sum=0;
	for(i=1;i<=b;i++)
	{
		sum+=power(i,k)*(b/i - (a-1)/i);
		sum%=MOD;
	}
	return sum;
}
int main()
{
	ll t,a,b,k,ans,i;
	sc(t);
	while(t--)
	{
		sc(a); sc(b); sc(k);
		printf("%lld\n",solve(a,b,k));
	}
}
