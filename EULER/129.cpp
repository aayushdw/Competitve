#include<stdio.h>
#define LIMIT 1000000
#define ll long long int
int main()
{
	ll i,p,k;
	for(i=LIMIT;;i++)
	{
		if(i%2==0||i%5==0)
		continue;
		p=1%i; k=1;
		while(p)
		{
			p=10*p+1;
			p%=i; k++;
		}
		if(k>LIMIT){
		printf("%lld %lld\n",i,k);
		return 0;}
	}
}
