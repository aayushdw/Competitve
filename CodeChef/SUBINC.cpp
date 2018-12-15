#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int 
int main()
{
	ll t,n,i,count,num;
	sc(t);
	while(t--)
	{
		sc(n); 
		ll a[n+1];
		a[n]=INT_MIN;
		for(i=0;i<n;i++)
		sc(a[i]);
		count=1; num=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				num+=(count*(count+1))/2;
				count=1;
			}
			else
			count++;
			//printf("%d %d %d\n",i,count,num);
		}
		printf("%lld\n",num);
	}
	return 0;
}
