#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lld",&x)
int main()
{
	long long int n,K,i,k,f,j,count=0;
	sc(n); sc(K);
	long long int a[n];
	for(i=0;i<n;i++)
	sc(a[i]);
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=i;j<n;j++)
		{
			for(k=i;k<j;k++)
			if(a[k]%a[j]==K)
			{
				f=1;
				break;
			}
			if(f)
			break;
			count++;
			//printf("%lld %lld\n",i,j);
		}
	}
	printf("%lld",count);
	return 0;
}
