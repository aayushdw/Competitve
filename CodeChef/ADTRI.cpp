#include<stdio.h>
#define MAX 5000005
#define sc(x) scanf("%d",&x)
int a[MAX+5]={0};
void pre()
{
	int i,j,k,p;
	for(i=1;i*i<MAX;i++)
	for(j=1;j*j<MAX;j++)
	{
		if(i==j||i*i+j*j>=MAX)
		continue;
		k=i*i+j*j;
		p=k;
		while(p<MAX)
		{
			a[p]=1;
			p+=k;
		}
	}
	return;
}
int main()
{
	pre();
	//return 0;
	int t,n;
	sc(t);
	while(t--)
	{
		//printf("%d ",t);
		sc(n);
		if(a[n])
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
