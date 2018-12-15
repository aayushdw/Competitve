#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lld",&x)
long long int nCr(long long int n,long long int r)
{
	if(r==0)
	return 1;
	if(n==r)
	return 1;
	return nCr(n-1,r)+nCr(n-1,r-1);
}
long long int poly(long long int a[],long long int n, long long int k)
{
	int i;
	long long int res=0;
	for(i=0;i<=n;i++)
	res+=a[i]*pow(k,i);
	return res;
}
int main()
{
	long long int n,i,j,r;
	sc(n);
	long long int a[n+1],p[n+1],c[n+1];
	for(i=0;i<=n;i++)
	sc(a[n-i]);
	for(i=0;i<=n;i++)
	{
		p[i]=poly(a,n,i);
		c[i]=p[i];
		//printf("%lld\n",p[i]);
	}
	
	c[1]-=c[0];
	for(i=2;i<=n;i++)
	{
		c[i]-=p[i-1];
		for(j=1;j<i;j++)
		c[i]-=nCr(i-1,j-1)*c[j];
	}
	for(i=0;i<=n;i++)
	printf("%d ",c[i]);
	return 0;
}
