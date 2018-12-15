#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
//int sum[51][51],prod[51][51];
int main()
{
	int t,n,i,j,s,p;
	sc(t);
	while(t--)
	{
		sc(n);
		int a[n],count=0;
		for(i=0;i<n;i++)
		sc(a[i]);
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(i==j)
				{
					count++;
					s=a[i];
					p=a[i];
				}
				else
				{
					s+=a[j];
					p*=a[j];
					if(s==p)
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
