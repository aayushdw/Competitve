#include<stdio.h>
#include<stdbool.h>
#define sc(x) scanf("%d",&x)
int bitXor(int a,int b)
{
	int x=(a&b);
	int y=(~a&~b);
	return (~x&~y);
}
int main()
{
	int t,n,a,i,j;
	sc(t);
	while(t--)
	{
		sc(n); sc(a);
		int list[n];
		for(i=0;i<n;i++)
		sc(list[i]);
		bool arr[1024]={0};
		arr[a]=1; arr[0]=1;
		for(i=0;i<n;i++)
		{
			for(j=1;j<1024;j++)
			{
				if(arr[j])
				arr[bitXor(j,list[i])]=1;
			}
		}
		int max=0;
		for(i=0;i<1024;i++)
		if(arr[i])
		max=i;
		printf("%d\n",max);
	}
	return 0;
}
