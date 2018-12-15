#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%d",&x)
int max(int a,int b)
{	return a>b?a:b;	}
int main()
{
	int t,n,m,i,j,x,y;
	char c;
	sc(t);
	while(t--)
	{
		sc(n); sc(m);
		int xmin=INT_MAX,xmax=-1,ymin=INT_MAX,ymax=-1,count=0,ans;
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				c=getchar();
				if(c=='.')
				continue;
				count++;
				if(j<ymin)
				ymin=j;
				if(j>ymax)
				ymax=j;
				if(i<xmin)
				xmin=i;
				if(i>xmax)
				xmax=i;
			}
		}
		//printf("xmax=%d xmin=%d\nymax=%d ymin=%d\n",xmax,xmin,ymax,ymin);
		if(count)
		{
			x=xmax-xmin+1;
			y=ymax-ymin+1;
			//printf("%d %d\n",x,y);
			ans=max((x+2)/2,(y+2)/2);
			printf("%d\n",ans);
		}
		else
		printf("0\n");
	}
	return 0;
}
