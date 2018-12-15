#include<stdio.h>
#define sc(x) scanf("%d",&x)
void toBase3(long long int n,long long int a[])
{
	long long int i=0;
	while(i<22)
	{
		a[i++]=n%3;
		n/=3;
	}
	return;
}
long long int pow(long long int base,long long int exp)
{
	long long int res=1;
	while(exp)
	{
		res*=base;
		exp--;
	}
	return res;
}
int main()
{
	long long int t,a[22],b[22],n,i,carry;
	sc(t);
	while(t--)
	{
		sc(n);
		toBase3(n,a);
		carry=0;
		for(i=0;i<22;i++)
		{
			a[i]+=carry;
			a[i]%=3;
			carry=a[i]/3;
			b[i]=0;
			if(a[i]==2)
			{
				a[i]=0;
				b[i]=1;
				carry=1;
			}
		}
		printf("left pan: ");
		for(i=21;i>=0;i--)
		if(b[i])
		printf("%lld ",pow(3,i));
		printf("\nright pan: ");
		for(i=21;i>=0;i--)
		if(a[i])
		printf("%lld ",pow(3,i));
		printf("\n\n");
	}
	return 0;
}
