#include<stdio.h>
#include<limits.h>
#define MAX 1000
#define ll long long int
ll A=1<<20;
ll B=1<<19;
ll a[MAX][MAX],s[MAX][MAX]={0};
void generate()
{
	ll i,j,t=0,p;
	for(i=0;i<MAX;i++)
	for(j=0;j<=i;j++)
	{
		t=(615949*t+797807);
		t%=A;
		a[i][j]=t-B;
		if(j)
		s[i][j]=a[i][j]+s[i][j-1];
		else
		s[i][j]=a[i][j];
	}
}
int main()
{
	generate();
	ll i,j,l;
	ll sum,min=INT_MAX;
	for(i=0;i<MAX;i++)
	for(j=0;j<=i;j++)
	{
		sum=a[i][j];
		if(sum<min)
		min=sum;
		for(l=2;l+i-1<MAX;l++)
		{
			sum+=s[i+l-1][j+l-1];
			if(j)
			sum-=s[i+l-1][j-1];
			if(sum<min)
			min=sum;
		}
	}
	printf("%lld",min);
}
