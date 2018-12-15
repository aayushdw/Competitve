#include<stdio.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int
#define MAX 100005
#define MOD 1000000007
ll arr[MAX]={0},a[MAX];
ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main()
{
	ll t,i,n,x,m,ans,mul,p;
	for(i=1;i<MAX;i++)
	arr[i]=modular_pow(i,MOD-2,MOD);
	sc(t);
	while(t--)
	{
		sc(n); sc(x); sc(m);
		for(i=0;i<n;i++)
		
		{
			sc(a[i]);
			a[i]%=MOD;
		}
		x--; m%=MOD;
		ans=0;
		mul=1;
		for(i=x;i>=0;i--)
		{
			ans+=a[i]*mul;
			ans%=MOD;
			p=x-i+1;
			mul*=(m+p-1)%MOD;
			mul%=MOD;
			mul*=arr[p];
			mul%=MOD;
			//printf("%lld %lld\n",i,mul);
		}
		printf("%lld\n",ans);
	}
}
