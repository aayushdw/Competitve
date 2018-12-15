#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000099
#define MOD 1000000007
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int primes[200000];
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
	int i,j=0,test,n,k,p;
	long long int r;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	sc(test);
	while(test--)
	{
		sc(n);
		i=0;
		k=primes[i++];
		r=1;
		while(k<=n)
		{
			p=n;
			while(1)
			{
				if(p>=k)
				{
					p/=k;
					r*=k;
					r%=MOD;
				}
				else
				break;
			}
			k=primes[i++];
		}
		printf("%lld\n",r);
	}
	return 0;
} 