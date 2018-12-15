#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%d",&x)
int a[100][100],n;
int maxdiff(int cost,int index)
{
	int j,max=0;
	for(j=1;j<=n;j++)
	{
		if(a[index][j]>max)
		max=a[index][j];
	}
	return cost-max;
}
int strategy(int index,int max)
{
	int j,k,index_j=0;
	for(j=1;j<=n;j++)
	{
		if(a[index][j]==0)
		continue;
		k=maxdiff(a[index][j],j);
		if(k>max)
		{
			max=k;
			index_j=j;
		}
	}
	return index_j;
}
int main()
{
	int i,j,k;
	sc(n);
	int max,index_i,index_j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	sc(a[i][j]);
	max=INT_MIN;
	for(i=1;i<=n;i++)
	{
		k=strategy(i,max);
		if(k)
		{
			index_i=i;
			index_j=k;
		}
	}
	printf("%d %d\n",index_i,index_j);
	fflush(stdout);
	a[index_i][index_j]=0;
	while(1)
	{
		if(maxdiff(0,index_j)==0)
		return 0;
		sc(index_i); sc(index_j);
		a[index_i][index_j]=0;
		if(maxdiff(0,index_j)==0)
		return 0;
		index_i=index_j;
		index_j=strategy(index_i,INT_MIN);
		printf("%d %d\n",index_i,index_j);
		fflush(stdout);
		a[index_i][index_j]=0;
	}
}
