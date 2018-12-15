#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int
ll min(ll a,ll b)
{
	return (a<b?a:b);
}
ll a[300005],h[300005],p[300005],e[300005];
int main()
{
	ll n,i,count,j,min,max,ene,i_next;
	sc(n);
	//n=30000;
	
	for(i=0;i<n;i++)
	sc(p[i]);
	//p[i]=i;
	
	for(i=0;i<n;i++)
	sc(a[i]);
	//a[i]=i;
	
	for(i=0;i<n;i++)
	sc(h[i]);
	//h[i]=i;
	
	
	//e[0]=a[0];
	i=0; count=a[0];
	while(i!=n-1)
	{
		min=INT_MAX;
		for(j=i+1;j<n;j++)
		{
			ene=a[j]+(h[j]-h[i])*(h[j]-h[i]);
			if(ene<=min&&p[j]>p[i])
			{
				min=ene;
				i_next=j;
			}
		}
		count+=min;
		i=i_next;
		//printf("%lld\n",i);
	}
	
	printf("%lld",count);
	
	return 0;
	
}
