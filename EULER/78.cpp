#include<stdio.h>
#define MAX 100
#define MOD 1000000
int a[MAX+1][MAX+1];
int main()
{
	int i,j;
	for(i=1;i<=MAX;i++)
	{
		a[i][i]=1;
		for(j=i-1;j>=1;j--)
		{
			a[i][j]=(a[i-j][j]+a[i][j+1])%MOD;
		}
		//if(a[i][1]==0)
		printf("%d %d\n",i,a[i][1]);
	}
	return  0;
}
