#include<stdio.h>
#define sc(x) scanf("%lld",&x)
long long int modExpo(long long int a,long long int b,long long int MOD)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x*=y;
			x%=MOD;
		}
		y*=y;
		y%=MOD;
		b/=2;
	}
	return x;
}
long long int inverseMod(long long int a,long long int MOD)
{
	return modExpo(a,MOD-2,MOD);
}
int main()
{
	long long int t,n,p,k,i;
	sc(t);
	while(t--)
	{
		sc(n); sc(p);
		if(n>=p)
		printf("0\n");
		else
		{
			k=p-1;
			for(i=n+1;i<p;i++)
			{
				k*=inverseMod(i,p);
				k%=p;
			}
			printf("%lld\n",k);
		}
	}
	return 0;
}
