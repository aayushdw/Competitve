#include<stdio.h>
#include<math.h>
#define ll long long int
bool isSquare(ll p)
{
	double a=sqrt(p);
	ll q=(int)a;
	if(q*q==p)
	return true;
	return false;
}
int main()
{
	ll i,j,k,a,b,c,d,e,f,x,y,z,result=0;
	bool solved=false;
	for(i=4;!solved;i++)
	{
		a=i*i;
		for(j=3;j<i && !solved;j++)
		{
			c=j*j;
			f=a-c;
			if(f<0|| !isSquare(f))
			continue;
			k=(j%2)?1:2;
			for(;k<j;k+=2)
			{
				d=k*k;
				e=a-d;
				b=c-e;
				if(b<=0 || e<=0 || !isSquare(b) || !isSquare(e))
				continue;
				x=(d+c)/2;
				y=(e+f)/2;
				z=(c-d)/2;
				result=x+y+z;
				solved=true;
				break;
			}
		}
	}
	printf("%lld %lld %lld\n%lld",x,y,z,result);
}
