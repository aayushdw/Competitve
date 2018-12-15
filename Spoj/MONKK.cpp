#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%d",&x)
int kadane(int a[],int sz,int n)
{
	if(n>sz)
	return -2;
	int i,sum=0,max=INT_MIN;
	for(i=0;i<n;i++)
	sum+=a[i];
	if(sum>max)
	max=sum;
	for(i=n;i<sz;i++)
	{
		sum-=a[i-n];
		sum+=a[i];
		if(sum>max)
		max=sum;
	}
	return max;
}
int main()
{
	int t,r,p,c,i,j,k,test;
	char ch;
	sc(test);
	for(t=1;t<=test;t++)
	{
		sc(r); sc(c);
		int a[r][c],b[r][c];
		for(i=0;i<r;i++)
		{
			getchar();
			for(j=0;j<c;j++)
			{
				ch=getchar();
				if(ch=='T')
				a[i][j]=-1;
				else if(ch=='B')
				a[i][j]=1;
				else
				a[i][j]=0;
				if(j)
				b[i][j]=b[i][j-1]+a[i][j];
				else
				b[i][j]=a[i][j];
			}
		}
		/*for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			printf("%d",b[i][j]);
			printf("\n");
		}*/
		int temp[r],MAX=0;
		for(i=0;i<c;i++)
		{
			for(j=0;j<=i;j++)
			{
				//printf("%d %d--\n",i,j);
				for(k=0;k<r;k++)
				{
					if(j)
					temp[k]=b[k][i]-b[k][j-1];
					else
					temp[k]=b[k][i];
					//printf("%d ",temp[k]);
				}
				//printf("\n");
				p=kadane(temp,r,i-j+1);
				//printf("%d\n",p);
				if(p>MAX)
				MAX=p;
			}
		}
		printf("Case %d: %d\n",t,MAX);
	}
	return 0;
}
