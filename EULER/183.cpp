#include<stdio.h>
#include<math.h>
#define e 2.71828182846
int check(int k)
{
	while(k%2==0)
	k/=2;
	while(k%5==0)
	k/=5;
	if(k!=1)
	return false;
	return true;
}
int gcd(int a, int b)
{
// base case
if (b == 0)
return a;
// a is greater
if (a > b)
return gcd(b, a%b);
return gcd(a, b%a);
}
int main()
{
	double n,p,q;
	int k,sum=0;
	for(int n=5;n<=10000;n++)
	{
		k=n/e;
		p=k*log(n*1.0/k); q=(k+1)*log(n*1.0/(k+1));
		if(q>p)
		k++;
		if(check(k/gcd(k,n)))
		sum-=n;
		else
		sum+=n;
		//printf("%d %d %d\n",n,k,check(k));
	}
	printf("%d",sum);
}
