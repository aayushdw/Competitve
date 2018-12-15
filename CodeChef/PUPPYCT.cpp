#include<stdio.h>
#define sc(x) scanf("%d",&x)
int a[1005][1005];
void fun(int x,int y,int n)
{
	int i=0;
	while(x-i>0&&y-i>0)
	{
		a[x-i][y-i]=1;
		i++;
	}
	i=0;
	while(x+i<=n&&y+i<=n)
	{
		a[x+i][y+i]=1;
		i++;
	}
	i=0;
	while(x-i>0&&y+i<=n)
	{
		a[x-i][y+i]=1;
		i++;
	}
	i=0;
	while(x+i<=n&&y-i>0)
	{
		a[x+i][y-i]=1;
		i++;
	}
}
int main()
{
	int t,n,k,i,j,x,y,count;
	long long int q,w;
	sc(t);
	while(t--)
	{
		sc(n); sc(k);
		if(k==0)
		{
			q=n;
			w=q*q;
			printf("%lld\n",w);
			continue;
		}
		if(k==1)
		{
			sc(x); sc(y);
			i=1;
			while(x+i<=n&&y+i<=n)
			{
				i++;
				count++;
			}
			i=1;
			while(x-i>0&&y-i>0)
			{
				i++;
				count++;
			}
			i=1;
			while(x-i>0&&y+i<=n)
			{
				count++;
				i++;
			}
			i=0;
			while(x+i<=n&&y-i>0)
			{
				count++;
				i++;
			}
			q=n;
			w=q*q-count;
			printf("%lld\n",w);
			continue;
		}
		count=0;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		a[i][j]=0;
		while(k--)
		{
			sc(x); sc(y);
			a[x][y]=1;
			fun(x,y,n);
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(!a[i][j])
		count++;
		printf("%d\n",count);
	}
	return 0;
} 
