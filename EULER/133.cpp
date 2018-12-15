#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 100000
bool t[MAX]={1,1,0};
ll primes[30000],count;
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
	ll i,j,p,q,r,a,k,c=0,f,sum=0;
	for(i=0;i<count;i++)
	{
		//printf("%lld\n",primes[i]);
		p=primes[i]; f=0;
		r=1; q=1; a=10;
		for(j=1;j<20;j++)
		{
			//printf ("%lld ",q);
			for(k=0;k<9;k++)
			{
				r*=a;	r%=p;
				r+=q;	r%=p;
			}
			ll b=a;
			for(k=0;k<9;k++)
			{
				a*=b;	a%=p;
			}
			q=r;
			if(!r)
			{
				f=1;
				break;
			}
		}
		if(!f)
		sum+=p;
		//printf("\n");
	}
	printf("%lld",sum);
}
