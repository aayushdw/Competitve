#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 999984+100
#define LIMIT 999966663333
#define M
bool t[MAX]={1,1,0};
ll primes[78500],count;
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
int main()
{
	seive();
	ll a,b,n,x,y,z,sum=0,f,i;
	for(i=1;primes[i]*primes[i]<=LIMIT;i++)
	{
		a=primes[i-1]; b=primes[i];
		n=b*b-a*a+1;
		x=n/a; y=n/b; z=(b*b)/(a*b);
		if(n%a)
		x++;
		if(n%b)
		y++;
		sum+=a*a*(x-1)+a*x*(x-1)/2;
		sum+=b*b*(y-1)-b*y*(y-1)/2;
		sum-=a*b*z*(z+1);
	}
	a=primes[i-1]; b=primes[i];
	for(i=a*a+1;i<LIMIT;i++)
	{
		f=0;
		if(i%a==0)
		f++;
		if(i%b==0)
		f++;
		if(f==1)
		sum+=i;
	}
	printf("%lld",sum);
}
