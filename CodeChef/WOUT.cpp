#include<stdio.h>
#include<stdlib.h>
#define sc(x) scanf("%lld",&x)
int main()
{
	long long int t,n,p,*a,*b,x,y,min,i,k,h,sum;
	sc(t);
	while(t--)
	{
		sc(n); sc(h);
		k=n;
		a=(long long int*)calloc(n+1,sizeof(long long int));
		b=(long long int*)calloc(n+1,sizeof(long long int));
		while(k--)
		{
			sc(x); sc(y);
			if(x)
			a[x-1]+=1;
			b[y+1]+=1;
		}
		/*for(i=0;i<n;i++)
		printf("%d",a[i]);*/
		for(i=n-1;i>=0;i--)
		a[i]+=a[i+1];
		for(i=1;i<n;i++)
		b[i]+=b[i-1];
		for(i=0;i<n;i++)
		a[i]+=b[i];
		sum=0;
		for(i=0;i<h;i++)
		sum+=a[i];
		min=sum;
		for(i=h;i<n;i++)
		{
			sum+=a[i];
			sum-=a[i-h];
			if(sum<min)
			min=sum;
		}
		printf("%lld\n",min);
	}
	return 0;
}
