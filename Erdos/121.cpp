#include<stdio.h>
#include<vector>
#define MAX 1000005
int pow2[30]={1},fib[35]={1,2};
int arr[MAX];
int main()
{
	int i,j,f;
	for(i=0;i<MAX;i++)
	arr[i]=-1;
	for(i=1;i<30;i++)
	{
		pow2[i]=2*pow2[i-1];
		if(pow2[i]<MAX)
		arr[pow2[i]]=1;
	}
	for(i=2;i<35;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]<MAX)
		arr[fib[i]]=1;
	}
	arr[1]=1;
	//printf("%d %d",arr[1],arr[2]);
	for(i=2;i<MAX;i++)
	{
		if(arr[i]==1)
		continue;
			j=1; f=0;
			while(i-pow2[j]>0)
			{
				if(arr[i-pow2[j]]==2)
				{
					f=1;
					arr[i]=1;
					break;
				}
				j++;
			}
			j=0;
			while(f==0&&i-fib[j]>0)
			{
				if(arr[i-fib[j]]==2)
				{
					arr[i]=1;
					f=1;
				}
				j++;
			}
			if(f==0)
			arr[i]=2;
	}
	int count=0;
	for(i=2;i<=1000000;i++)
	if(arr[i]==2)
	count++;
	printf("%d",count);
}
