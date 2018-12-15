#include<stdio.h>
#include<math.h>
#define sci(x) scanf("%d",&x)
#define scf(x) scanf("%lf",&x)
int main()
{
	int t,m,n,i,j;
	double k;
	sci(t);
	while(t--)
	{
		sci(n); sci(m);
		double p[n],sum=0;
		for(i=0;i<n;i++)
		{
			p[i]=0;
			int f=0;
			for(j=0;j<m;j++)
			{
				scf(k);
				if(k==0||f==1)
				{
					f=1;
					p[i]=-1;
					continue;
				}
				p[i]+=log10(k);
			}
		}
		if(p[0]==-1)
		printf("0.000000\n");
		else
		{
			double a,b;
			a=floor(p[0]);
			a*=-1;
			a++;
			sum=0;
			for(i=0;i<n;i++)
			{
				if(p[i]==-1)
				continue;
				p[i]+=a;
				p[i]=pow(10,p[i]);
				sum+=p[i];
			}
			printf("%0.6lf\n",p[0]/sum);
		}
	}
	return 0;
}
