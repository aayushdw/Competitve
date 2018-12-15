#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 50100
#define MOD 1000000007
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int primes[6000];
void seive()
{
	int i=2,j;
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
	return;
}
int main()
{
	seive();
	int test,i,j=0,n,p,k,c;
	for(i=0;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	long long int numDiv;
	sc(test);
	while(test--)
	{
		sc(n); i=0;
		//if(n==0)
		//printf("1\n");
		k=primes[i++];
		numDiv=1;
		while(k*k<=n)
		{
			p=n; c=0;
			while(p)
			{
				c+=p/k;
				p/=k;
			}
			numDiv*=c+1;
			numDiv%=MOD;
			k=primes[i++];
		}
		while(k<=n)
		{
			numDiv*=n/k+1;
			numDiv%=MOD;
			k=primes[i++];
		}
		printf("%lld\n",numDiv);
	}
	return 0;
}
