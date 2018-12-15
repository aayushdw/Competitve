#include<stdio.h>
#define sc(x) scanf("%d",&x)
int min(int a, int b)
{
	return a<b?a:b;
}
int fun(int r,int s,int j,int k)
{
	if(k<=s)
	{
		if(j>=r)
		return 0;
		else
		return r-j;
	}
	else
	{
		if(j>=r)
		return k-s;
		else
		return k-s+r-j;
	}
}
 
int main()
{
	int i,j,p,q,r,s,n,m,k,count=0,x;
	sc(n); sc(m);
	int a[n+1][5],b[n+1][33][33];
	for(i=0;i<n+1;i++)
	a[i][2]=0;
	for(i=0;i<33;i++)
	for(j=0;j<33;j++)
	b[1][i][j]=0;
	for(i=0;i<m;i++)
	{
		sc(p);	sc(q);	sc(r);	sc(s);
		a[p][1]=q;
		a[q][0]=p;
		a[p][2]=1;
		a[q][3]=r;
		a[q][4]=s;
		for(j=0;j<33;j++)
		for(k=j;k<33;k++)
		b[q][j][k]=b[p][j][k]+fun(r,s,j,k);
	}
	
	for(i=1;i<n+1;i++)
	if(!a[i][2])
	count++;
	//printf("%d",count);
	
	p=0;
	int c[count][33][33],d[33][33];
	for(i=1;i<n+1;i++)
	if(!a[i][2])
	{
		for(j=1;j<33;j++)
		for(k=j;k<33;k++)
		c[p][j][k]=b[i][j][k];
		p++;
	}
	
	
	for(i=1;i<33;i++)
	for(j=i;j<33;j++)
	{
		x=c[0][i][j];
		for(k=1;k<count;k++)
		x=min(x,c[k][i][j]);
		d[i][j]=x;
	}
	/*
	for(i=1;i<33;i++)
	printf("%2d ",i);
	printf("\n");
	for(i=1;i<33;i++)
	{
	for(j=1;j<33;j++)
	{
	    if(j<i)
	    printf("%2d ",0);
	    else
	    printf("%2d ",d[i][j]);
	}
	printf("\n");
	}
	*/
	int e[33]={0,d[1][1]};
	for(i=2;i<33;i++)
	{
		x=d[1][i];
		for(j=2;j<=i;j++)
		x=min(x,e[j-1]+d[j][i]);
		e[i]=x;
	}
	printf("%d",e[32]);
	return 0;
} 
