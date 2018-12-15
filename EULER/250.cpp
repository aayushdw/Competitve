#include<stdio.h>
#define ll long long int
#define MAX 250250
#define LIMIT 500
#define MOD 10000000000000000
ll arr[MAX]={0},a[LIMIT]={1};
ll modulo(ll a,ll b,ll c)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}
int main()
{
	ll i,j;
	for(i=1;i<=MAX;i++)
	arr[i]=modulo(i,i,250);
	for(i=1;i<=MAX;i++)
	{
		for(j=LIMIT-arr[i]-1;j>=0;j--)
		{
			a[j+arr[i]]+=a[j];
			a[j+arr[i]]%=MOD;
		}
		for(j=250;j<LIMIT;j++)
		{
			a[j%250]+=a[j];
			a[j]=0;
			a[j%250]%=MOD;
		}
	}
	printf("%lld",a[0]-1);
}
