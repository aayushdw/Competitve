#include<stdio.h>
#include<bitset>
#define M 10
#define MAX M+5
#define ll long long int
using namespace std;
bitset<MAX> t;
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
			t.set(i*j);
			j++;
		}
		i++;
	}
	return;
}
int main()
{
	seive();
	ll sum=0,i,p;
	for(i=2;i<M;i++)
	{
		if(!t[i])
		{
			p=i;
			while(p)
			{
				sum+=p%10;
				p/=10;
			}
		}
	}
	printf("%lld",sum);
}
