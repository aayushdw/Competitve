#include<stdio.h>
#include<iostream>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define ll long long int
#define MAX 1000+5
#define LIMIT 1000000000000000000
using namespace std;
double pc[MAX][MAX]={0},ad[MAX][MAX]={0};
ll buy[MAX][MAX],sell[MAX][MAX];
double max(double a,double b)
{
    return a>b?a:b;
}
int main()
{
	ll i,j,d,n,m,k,t;
	double ma;
	scll(n); scll(m); scll(d);
	for(i=0;i<n;i++)
	for(j=0;j<2*m;j++)
	{
		if(j%2)
		sc(buy[j/2][i]);
		else
		sc(sell[j/2][i]);
	}
	for(i=0;i<n;i++)
	pc[0][i]=d;
	for(i=0;i<n;i++)
	{
	ad[0][i]=d*1.0/sell[0][i];
	//printf("%lld ",sell[0][i]);
	}
	//printf("\n");
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			ma=pc[i-1][j];
			if(j>0)
			ma=max(ma,pc[i-1][j-1]);
			if(j<n-1)
			ma=max(ma,pc[i-1][j+1]);
			ma=max(ma,ad[i-1][j]*buy[i][j]);
			pc[i][j]=ma;
			if(ma>LIMIT)
				{
				    printf("Quintillionnaire");
				    return 0;
				}
			
			
			ma=ad[i-1][j];
			if(j>0)
			ma=max(ma,ad[i-1][j-1]);
			if(j<n-1)
			ma=max(ma,ad[i-1][j+1]);
			ma=max(ma,pc[i-1][j]/sell[i][j]);
			ad[i][j]=ma;
			if(ma>LIMIT)
				{
				    printf("Quintillionnaire");
				    return 0;
				}
			
		}
	}
	/*
	for(i=0;i<m;i++)
	{
	    for(j=0;j<n;j++)
	    printf("%0.3lf ",pc[i][j]);
	    printf("\n");
	}
	for(i=0;i<m;i++)
	{
	    for(j=0;j<n;j++)
	    printf("%0.3lf ",ad[i][j]);
	    printf("\n");
	}*/
	double ans=0;
	for(i=0;i<n-1;i++)
	if(pc[m-1][i]>ans)
	ans=pc[m-1][i];
	printf("%0.9lf",ans);
}
