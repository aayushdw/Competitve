//Editorial: https://docs.google.com/document/d/1lyyoFhnM7GRJFReInjqHJ4MhjMkuPdZItIQtVvXYJqY/edit
#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX 31622800
#define LIM 1000000000000000
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define plld(t) printf("%lld\n",t)
ll phi[MAX+5];
 
void precalc()
{
	for(int i=1;i<=MAX;i++)
		phi[i]=i;
		
	for(int i=2;i<=MAX;i+=2)
		phi[i]-=phi[i]/2;
 
	for(int i=3;i<=MAX;i+=2)
		if(phi[i]==i)
			for(int j=i;j<=MAX;j+=i)
				phi[j]-=phi[j]/i;
}
ll S(ll x)
{
	ll u=floor(sqrt(x));
	ll ans=0;
	for(int i=1;i<=u;i++)
	ans+=2*(x/i);
	return ans-u*u;
}
int main()
{
	precalc();
	ll p,ans=0;
	for(p=1;p*p<=LIM;p++)
	{
		ans+=phi[p]*S(LIM/(p*p));
	}
	printf("%lld",ans);
}
