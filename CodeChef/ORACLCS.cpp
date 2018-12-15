#include<stdio.h>
#include<strings.h>
#define sc(x) scanf("%d",&x)
int check(int p,char arr[101][101],int a[2][101],int l,int n)
{
	int count=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=a[1][i]+1;j<=l;j++)
		if(arr[i][j]-'a'==p)
		{
			count++;
			break;
		}
	}
	if(count==n)
	return 1;
	return 0;
}
int main()
{
	int t,n,i,j,m,k;
	sc(t);
	while(t--)
	{
		sc(n);
		char arr[101][101];
		int a[2][101]={0},index=0;
		//for(i=;i<4;i++)
		for(j=0;j<n;j++)
		a[1][j]=-1;
		for(i=0;i<n;i++)
		scanf("%s",arr[i]);
		m=strlen(arr[0]);
		//printf("%d\n",m);
		for(i=0;i<m;i++)
		{
			//printf("%d %d\n",check(0,arr,a,i,n),check(1,arr,a,i,n));
			if(check(0,arr,a,i,n))
			{
				a[0][index]=0;
				index++;
				for(j=0;j<n;j++)
				{
					for(k=a[1][j]+1;k<=i;k++)
					if(arr[j][k]-'a'==0)
					{
						a[1][j]=k;
						break;
					}
				}
			}
			else if(check(1,arr,a,i,n))
			{
				a[0][index]=1;
				index++;
				for(j=0;j<n;j++)
				{
					for(k=a[1][j]+1;k<=i;k++)
					if(arr[j][k]-'a'==1)
					{
						a[1][j]=k;
						break;
					}
				}
			}
			for(j=0;j<n;j++ )
			printf("%d ",a[1][j]);
			printf("\n");
		}
		printf("%d\n",index);
	}
	return 0;
}
