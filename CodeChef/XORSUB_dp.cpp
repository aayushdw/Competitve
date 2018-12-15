#include<stdio.h>
#include<stdbool.h>
#define sc(x) scanf("%d",&x)
int max(int a,int b)
{
	if(a>b)
	return a;
	return b;
}
int bitXor(int a,int b)
{
	int x=(a&b);
	int y=(~a&~b);
	return (~x&~y);
}
int main()
{
	int t,n,p,i,j,m,k;
	sc(t);
	while(t--)
	{
		sc(n); sc(p);
		int a[n];
		for(i=0;i<n;i++)
		sc(a[i]);
		int arr[n];
		arr[0]=max(p,bitXor(p,a[0]));
		for(i=1;i<n;i++)
		{
			m=0;
			for(j=0;j<i;j++)
			{
				k=max(arr[j],bitXor(arr[j],a[i]));
				m=max(k,m);
			}
			arr[i]=m;
		}
		printf("%d\n",arr[n-1]);
	}
	return 0;
}
