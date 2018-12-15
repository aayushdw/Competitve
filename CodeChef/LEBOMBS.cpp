#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,d,i,count=0;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		char a[n];
		scanf("%s",&a);
		if(n==1&&a[0]==0)
		{
			printf("1\n");
			continue;
		}
		if(n==1&&a[0]==1)
		{
			printf("0\n");
			continue;
		}
		if(!a[0]&&!a[1])
		count++;
		if(!a[n-2]&&!a[n-1])
		count++;
		for(i=1;i<n-1;i++)
		{
			if(a[i])
			continue;
			if(a[i-1]||a[i+1])
			continue;
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
