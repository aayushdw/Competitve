#include<stdio.h>
#define ll long long int
#define M 1250001
ll getCount(ll NUM,ll MOD)
{
	ll p=NUM*NUM,count=2;
	while(p!=NUM%MOD)
	{
		p*=NUM;
		p%=MOD;
		count++;
	}
	return count;
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
ll solve(ll a,ll b,ll MOD)
{
	ll q=a;
	for(ll i=2;i<b;i++)
	{
		q=modulo(a,q,MOD);
	}
	return modulo(a,q,MOD);
}
int main()
{
	ll a=1777,b=1855,MOD=100000000;
	ll x=solve(a,b,MOD);
	printf("%lld",x);
	return 0;
}
