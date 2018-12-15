#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lld",&x)
#define MOD 1000000007
#define MAX 1024
#define ll long long int 
ll get_dec()
{
	ll i;
	char s[15];
	scanf("%s",s);
	//printf("%s\n",s);
	ll num=0;
	for(i=0;i<10;i++)
	if(s[i]=='w'||s[i]=='+')
	num+=pow(2,9-i);
	return num;
}
ll modular_pow(ll base, ll exponent, ll modulus)
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
	ll t,p,n,i;
	sc(t);
	while(t--)
	{
		p=get_dec();
		sc(n);
		ll a[1024]={0},arr[1024][2]={0},j,k,x,y;
		arr[p][0]++; arr[p][1]++;
		
		for(i=0;i<n;i++)
		{
			p=get_dec();
			a[p]++;
		}
		
		for(i=0;i<1024;i++)
		{
			if(!a[i])
			continue;
		    n=a[i];
		    x=modular_pow(2,n-1,MOD);
		    y=(x-1)%MOD;
		    for(j=0;j<1024;j++)
		    arr[j][1]=0;
			for(j=0;j<1024;j++)
			{
				k=i^j;
				arr[k][1]+=(x*arr[j][0]);
				arr[k][1]%=MOD;
				arr[j][1]+=(y*arr[j][0]);
				arr[j][1]%=MOD;
			}
			for(j=0;j<1024;j++)
			{
			    arr[j][0]+=arr[j][1];
			    arr[j][0]%=MOD;
			}
		}
		
		printf("%lld\n",arr[0][0]);
	}
	return 0;
}
