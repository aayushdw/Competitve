#include<stdio.h>
#include<math.h>
#include <limits.h>
#include<stdlib.h>
#define sc(x) scanf("%d",&x)
#define rep(i,a,b) for(i=a;i<b;i++)
int n,final_x,final_y;
int min(int a,int b,int c,int d)
{
	int x=a<b?a:b,y=c<d?c:d;
	return x<y?x:y;
}
void solve(int **a,int **b,int x,int y,int p)
{
	if(!a[x][y])
	return;
	if(x==final_x&&y==final_y)
	{
		b[x][y] = min(b[x-1][y],b[x+1][y],b[x][y-1],b[x][y+1])+1;
		return;
	}
	printf("%d %d\n",x,y);
	b[x][y]=min(b[x-1][y],b[x+1][y],b[x][y-1],b[x][y+1])+1;
	if(x==n+1&&y==n+1){
	solve(a,b,x-1,y);
	solve(a,b,x+1,y);
	solve(a,b,x,y+1);
	solve(a,b,x,y-1);}
	if(p==1)
	{
	solve(a,b,x-1,y,1);
	//solve(a,b,x+1,y,2);
	solve(a,b,x,y+1,3);
	solve(a,b,x,y-1,4);
	}
	if(p==2)
	{
	//solve(a,b,x-1,y,1);
	solve(a,b,x+1,y,2);
	solve(a,b,x,y+1,3);
	solve(a,b,x,y-1,4);
	}
	if(p==3)
	{
	solve(a,b,x-1,y,1);
	solve(a,b,x+1,y,2);
	solve(a,b,x,y+1,3);
	solve(a,b,x,y-1,4);
	}
	if(p==1)
	{
	solve(a,b,x-1,y,1);
	//solve(a,b,x+1,y,2);
	solve(a,b,x,y+1,3);
	solve(a,b,x,y-1,4);
	}
	return;
}
int main()
{
	int t,x,y,k,i,j;
	char c;
	sc(t);
	while(t--)
	{
		sc(n);
		x=n+1,y=n+1;
		int **a,**b;
		a=(int**)calloc(2*n+3,sizeof(int*));
		b=(int**)calloc(2*n+2,sizeof(int*));
		for(i=0;i<2*n+3;i++)
		{
			a[i]=(int*)calloc(2*n+3,sizeof(int));
			b[i]=(int*)calloc(2*n+3,sizeof(int));
		}
		for(i=0;i<2*n+3;i++)
		for(j=0;j<2*n+3;j++)
		{
			a[i][j]=0;
			b[i][j]=1000;
		}
		b[n+1][n+1]=0; a[n+1][n+1]=1;
		for(k=0;k<n;k++)
		{
			getchar();
			c=getchar();
			if(c=='N')
			y++;
			if(c=='S')
			y--;
			if(c=='E')
			x--;
			if(c=='W')
			x++;
			a[x][y]=1;
		}
		final_x=x;
		final_y=y;
		/*rep(i,0,2*n+3){
		rep(j,0,2*n+3)
		printf("%d ",b[i][j]);
		printf("\n");}*/
		solve(a,b,n+1,n+1);
		printf("%d\n",b[final_x][final_y]);
	}
	return 0;
}
