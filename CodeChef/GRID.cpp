#include<stdio.h>
#define sc(x) scanf("%d",&x)
char a[1005][1005];
int arr[1005][1005];
int main()
{
	int t,n,i,j,num,flag;
	sc(t);
	while(t--)
	{
		sc(n);
		for(i=0;i<n;i++)
		scanf("%s",a[i]);
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		arr[i][j]=1;
		for(i=0;i<n;i++)
		{
			flag=1;
			for(j=n-1;j>=0;j--)
			{
				if(a[i][j]=='#')
				flag=0;
				if(!arr[i][j])
				continue;
				if(flag)
				arr[i][j]=1;
				else
				arr[i][j]=0;
			}
		}
		for(j=0;j<n;j++)
		{
			flag=1;
			for(i=n-1;i>=0;i--)
			{
				if(a[i][j]=='#')
				flag=0;
				if(!arr[i][j])
				continue;
				if(flag)
				arr[i][j]=1;
				else
				arr[i][j]=0;
			}
		}
		num=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		num+=arr[i][j];
		printf("%d\n",num);
	}
	return 0;
}
