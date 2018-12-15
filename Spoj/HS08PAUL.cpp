#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000005
#define MAXM 10000005
#define sc(x) scanf("%d",&x)
bool t[MAX]={1,1,0};
int a[MAXM]={0},b[MAXM]={0};
void seive()
{
	int i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	return;
}
int main()
{
	seive();
	int x,y,i,p,temp,k;
	for(x=1;x*x<MAXM;x++)
	{
		for(y=1;x*x+y*y*y*y<MAXM;y++)
		{
			k=x*x+y*y*y*y;
			if(!t[k])
			{
				a[k]=1;
				//printf("%d\n",k);
			}
		}
	}
	for(i=0;i<MAXM;i++)
	{
		if(a[i])
		b[i]=b[i-1]+1;
		else
		b[i]=b[i-1];
	}
	sc(temp);
	while(temp--)
	{
		sc(p);
		printf("%d\n",b[p]);
	}
	return 0;
}
