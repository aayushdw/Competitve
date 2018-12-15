#include<stdio.h>
#include<math.h>
#define sci(x) scanf("%lld",&x)
#define scf(x) scanf("%lf",&x)
int main()
{
	long long int t,n,m,p,b,i,x;
	double r[5],k[5],a,b1,c,res,sum=0;
	sci(t);
	sci(n); sci(p); sci(m); sci(b);
	for(i=1;i<5;i++)
	{
		scf(r[i]);
		k[i]=1.0/r[i];
	}
	a=-2*k[1]+2*k[2];
	while(t--)
	{
		n=(p*n)%m+b;
		if(n<5)
		sum+=r[n];
		else
		{
			x=n-4;
			res=x*(x+1)*a/2+(x+1)*k[4]-x*k[3];
			sum+=1.0/res;
		}
	}
	printf("%0.6lf",sum);
	return 0;
}
