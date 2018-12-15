#include<stdio.h>
#define MAX 100000000
#define sc(x) scanf("%d",&x)
int a[65]={1};
int search(int p)
{
	int i=0;
	for(i=0;;i++)
	{
		if(a[i]==p)
		return 1;
		if(a[i]>p)
		return 0;
	}
}
int main()
{
	int i=1,p,n,t,count;
	while(a[i-1]<MAX)
	{
		a[i]=a[i-1]*2;
		i++;
	}
	sc(t);
	while(t--)
	{
		sc(p); sc(n);
		count=0;
		while(1)
		{
			if(p==n)
			{
				printf("%d\n",count);
				break;
			}
			else if(search(p))
			{
				if(p<n)
				p*=2;
				else
				p/=2;
			}
			else 
			{
				if(p%2)
				p=(p-1)/2;
				else
				p/=2;
			}
			count++;
		}
	}
	return 0;
}
