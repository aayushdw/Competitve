#include<stdio.h>
#define MAX 100000
int main()
{
	int arr[MAX]={1},i,j;
	for(i=1;i<MAX;i++)
	{
		if(i%1000==0)
		{
			printf("%d\n",i);
		}
		for(j=i;j<MAX;j++)
		{
			arr[j]+=arr[j-i];
			arr[j]%=100000000;
		}
		if(arr[i]%1000000==0)
		{
			printf("%d %d",i,arr[i]);
			return 0;
		}
	}
	return 0;
}
