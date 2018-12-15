#include<stdio.h>
#include<stdbool.h>
#define sc(x) scanf("%d",&x)
int a[20][20],b[20][20];
bool solve(int m,int n,int i,int j)
{
    if(i<0||i>=m||j<0||j>=n)
	return 0;
	if(a[i][j]||b[i][j])
	return 0;
	b[i][j]=1;
	if(i==0||i==m-1||j==0||j==n-1)
	return 1;
	return (solve(m,n,i-1,j)||solve(m,n,i+1,j)||solve(m,n,i,j-1)||solve(m,n,i,j+1));
}

int main()
{
	int t,m,n,i,j,f,ex[2],en[2];
	char c;
	sc(t);
	while(t--)
	{
		sc(m); sc(n); getchar();
		for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		b[i][j]=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				c=getchar();
				if(c=='#')
				a[i][j]=1;
				else
				a[i][j]=0;
			}
			getchar();
		}
		f=0;
		for(i=0;i<n;i++)
		if(a[0][i]==0)
		{
			if(f==0)
			{
				en[0]=0; en[1]=i;
			}
			if(f==1)
			{
				ex[0]=0; ex[1]=i;
			}
			f++;
		}
		for(i=1;i<m;i++)
		if(a[i][n-1]==0)
		{
			if(f==0)
			{
				en[0]=0; en[1]=i;
			}
			else
			{
				ex[0]=0; ex[1]=i;
			}
			f++;
		}
		for(i=1;i<n-1;i++)
		if(a[m-1][i]==0)
		{
			if(f==0)
			{
				en[0]=0; en[1]=i;
			}
			else
			{
				ex[0]=0; ex[1]=i;
			}
			f++;
		}
		for(i=1;i<m;i++)
		if(a[i][0]==0)
		if(a[m-1][i]==0)
		{
			if(f==0)
			{
				en[0]=0; en[1]=i;
			}
			else
			{
				ex[0]=0; ex[1]=i;
			}
			f++;
		}
		if(f!=2)
		{
			printf("invalid %d\n",f);
			continue;
		}
		printf("%d %d\t%d %d\n",en[0],en[1],ex[0],ex[1]);
		if(solve(m,n,en[0],en[1]))
		printf("valid\n");
		else
		printf("invalid\n");
	}
	return 0;
}
