#include<stdio.h>
#define sc(x) scanf("%d",&x)
int arr[100002]={0};
int main()
{
	int i,n,p;
	sc(n);
	for(i=0;i<n;i++)
	{
		sc(p);
		arr[p]=1;
	}
	for(i=1;i<=n;i++)
	if(!arr[i])
	printf("%d ",i);
	return 0;
}
