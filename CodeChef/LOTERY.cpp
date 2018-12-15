#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX_NUM 1010
#define sc(x) scanf("%lld",&x)
#define ll long long int
#define MOD 1000000007
#define MAX 15
bool t[MAX_NUM]={1,1,0};
ll f[MAX][MAX]={0},g[MAX][MAX]={0},m[MAX][MAX]={0},c[1000005],d[1000005];
int primes[500];
void seive()
{
	int i=2,j;
	while(i*i<MAX_NUM)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX_NUM)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}
void pre()
{
	ll i,j,l;
	for(i=1;i<MAX;i++)
	{
		f[i][1]=i;
		g[i][1]=i;
		m[i][1]=i;
	}
	for(i=2;i<MAX;i++)
	{
		for(j=2;j<=i;j++)
		{
			
		}
		printf("\n");
	}
	return;
}
int main()
{
	pre();
	ll t,n,k,a,b,mod,i,j,ans;
	
	for(i=1;i<15;i++)
	{
		for(j=1;j<=i;j++)
		printf("%lld ");
		printf("\n");
	}
	sc(t);
	sc(n); sc(k); 
	sc(a); sc(b); sc(mod);
	for(i=2;i<=t;i++)
	sc(c[i]);
	for(i=2;i<=t;i++)
	sc(d[i]);
	for(i=1;i<t;i++)
	{
		ans=n;
		printf("%lld\n",ans);
		n=1+(a*ans+c[i+1])%mod;
		k=1+(b*ans+d[i+1])%n;
	}
	printf("%lld");
	return 0;
}
