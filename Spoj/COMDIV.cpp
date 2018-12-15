#include<stdio.h>
#define MAX 1000005
#define sc(x) scanf("%d",&x)
int numDiv[MAX]={0};
void pre()
{
	int i,j;
	for(i=1;i<MAX;i++)
	{
		for(j=1;j*i<MAX;j++)
		numDiv[i*j]++;
	}
	return;
}
int gcd(int a,int b)
{
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a>=b)
	return gcd(a%b,b);
	if(b>a)
	return gcd(b%a,a);
}
int main()
{
	pre();
	int t,a,b,k;
	sc(t);
	while(t--)
	{
		sc(a); sc(b);
		k=gcd(a,b);
		printf("%d\n",numDiv[k]);
	}
	return 0;
}
