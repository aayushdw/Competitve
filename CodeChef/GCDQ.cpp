#include<stdio.h>
#define sc(x) scanf("%d",&x)
int a[100005],b[100005],c[100005];
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int t,n,q,i,l,r;
	sc(t);
	while(t--)
	{
		sc(n); sc(q);
		for(i=1;i<=n;i++)
		sc(a[i]);
		b[1]=a[1]; c[n]=a[n];
		for(i=2;i<=n;i++)
		b[i]=gcd(a[i],b[i-1]);
		for(i=n-1;i>0;i--)
		c[i]=gcd(a[i],c[i+1]);
		/*for(i=1;i<=n;i++)
		printf("%d ",b[i]);
		printf("\n");
		for(i=n;i>0;i--)
		printf("%d ",c[i]);*/
		while(q--)
		{
			sc(l); sc(r);
			if(l==1)
			printf("%d\n",c[r+1]);
			else if(r==n)
			printf("%d\n",b[l-1]);
			else
			printf("%d\n",gcd(b[l-1],c[r+1]));
		}
	}
	return 0;
}
