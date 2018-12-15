#include<stdio.h>
#include<stdlib.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int
#define MOD 1000000007
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll n,i,j,sa=0,sb=0,m,ans;
	//sc(n);
	n=100000;
	//a[n+1],b[n+1],c[n+1],d[n+1];
	ll *a,*b;
	a=(ll*)calloc(n+1,sizeof(ll));
	b=(ll*)calloc(n+1,sizeof(ll));
	for(i=1;i<=n;i++)
	{
		//sc(a[i]);
		a[i]=i;
		a[i]+=i;
		sa+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		//sc(b[i]);
		b[i]=i;
		b[i]+=i;
		sb+=b[i];
	}
	sa%=MOD; sb%=MOD;
	ans=(sa*sb)%MOD;
	printf("%lld ",ans);
	for(i=2;i<=n;i++)
	{
		for(j=1;i+j<=n+1;j++)
		{
			m=max(a[j],a[i+j-1]);
			sa=sa-a[j]+m;
			a[j]=m;
			m=max(b[j],b[i+j-1]);
			sb=sb-b[j]+m;
			b[j]=m;
		}
		sa-=a[j];
		sb-=b[j];
		if(sa>=MOD)
		sa%=MOD;
		if(sa<0)
		{
			sa%=MOD;
			sa+=MOD;
		}
		if(sb>=MOD)
		sb%=MOD;
		if(sb<0)
		{
			sb%=MOD;
			sb+=MOD;
		}
		ans=(sa*sb)%MOD;
		//printf("%lld ",ans);
	}
	return 0;
}
