#include<stdio.h>
#include<math.h>
#define sc(x) scanf("%lld",&x)
#define scf(x) scanf("%lf",&x)
int a[12][60];
void print(int i)
{
	if(i>9)
	printf("%d",i);
	else
	printf("0%d",i);
	return;
}
int main()
{
	int t,i,j;
	for(i=0;i<12;i++)
	{
	for(j=0;j<60;j++)
	{
		a[i][j]=abs(60*i-11*j);
		if(a[i][j]>=361)
		a[i][j]=720-a[i][j];
	}
	}
	double p;
	int k;
	sc(t);
	while(t--)
	{
		scf(p);
		if(p-(int)p<1.0/120)
		{
			k=(int)p;
			k*=2;
		}
		else if(p-(int)p>119.0/120)
		{
			k=(int)p+1;
			k*=2;
		}
		else if(p-(int)p>59.0/120&&p-(int)p<61.0/120)
		{
			k=(int)p;
			k=2*k+1;
		}
		else
		continue;
		for(i=0;i<12;i++)
		for(j=0;j<60;j++)
		{
			if(k==a[i][j])
			{
				print(i);
				printf(":");
				print(j);
				printf("\n");
				//printf("%d\n",a[i][j]);
			}
		}
	}
	return 0;
}
