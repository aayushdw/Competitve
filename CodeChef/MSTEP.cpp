#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%d",&x)
int dist(int x1,int y1,int x2,int y2)
{
	return (abs(x1-x2)+abs(y1-y2));
}
int main()
{
	int n,t,sum,i,j,p;
	sc(t);
	while(t--)
	{
		sc(n);
		sum=0;
		int a[n*n+1][2];
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			sc(p);
			a[p][0]=i;
			a[p][1]=j;
		}
		for(i=1;i<n*n;i++)
		sum+=dist(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
		printf("%d\n",sum);
	}
	return 0;
}
