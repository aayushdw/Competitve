#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
int main()
{
	ll t,n,i,count,p;
	sc(t);
	while(t--)
	{
		sc(n);
		char a[n+1], b[n+1];
		scanf("%s",a);
		scanf("%s",b);
		count=0;
		for(i=0;i<n;i++)
		if(a[i]==b[i])
		count++;
		if(count==n)
		{
			for(i=0;i<=n;i++)
			sc(p);
			printf("%lld\n",p);
			continue;
		}
		ll max_win=-1;
		for(i=0;i<=n;i++)
		{
			sc(p);
			if(i<=count&&max_win<p)
			max_win=p;
		}
		printf("%lld\n",max_win);
	}
	return 0;
}
