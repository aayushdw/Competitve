#include<stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
	int n,i,j;
	sc(n);
	int a[n+1][n+1],b[n+1][n+1],max=0,index_i,index_j,flag;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		sc(a[i][j]);
		b[i][j]=0;
		if(a[i][j]>max)
		{
			index_i=i;
			index_j=j;
			max=a[i][j];
		}
	}
	printf("%d %d\n",index_i,index_j);
	fflush(stdout);
	b[index_i][index_j]=1;
	while(1)
	{
		flag=0;
		for(i=1;i<=n;i++)
		{
			if(b[index_j][i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		return 0;
		sc(index_i); sc(index_j);
		a[index_i][index_j]=0;
		index_i=index_j;
		max=0;
		for(j=1;j<=n;j++)
		if(b[index_i][j]==0&&max<a[index_i][j])
		{
			max=a[index_i][j];
			index_j=j;
		}
		if(max==0)
		return 0;
		printf("%d %d\n",index_i,index_j);
		fflush(stdout);
		b[index_i][index_j]=1;
	}
	
}
