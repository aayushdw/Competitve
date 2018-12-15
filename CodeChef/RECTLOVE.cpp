#include<stdio.h>
#include "BigIntegerLibrary.hh"
#define sc(x) scanf("%lld",&x)
#define ll long long int
int main()
{
	IifInt i,j,n,m,k,t,num,sum,row,col,p;
	sc(t);
	while(t--)
	{
		sc(n); sc(m); sc(k); sum=0;
		for(i=0;i<k;i++)
		{
			sc(p);
			if(p%m==0)
			{
				row=p/m;
				col=m;
			}
			else
			{
				row=p/m+1;
				col=p%m;
			}
			num=row*col;
			row=n+1-row;
			col=m+1-col;
			num*=row*col;
			sum+=num;
		}
		num=(n+1)*(m+1)*n*m/4;
		double ans=sum*1.0/num;
		printf("%0.9lf\n",ans);
	}
	return 0;
}
