#include<stdio.h>
#define ll long long int
#define LIMIT 1000000000000000
char s[50]="UDDDUdddDDUDDddDdDddDDUDDdUUDd";
ll solve(ll n,ll sz)
{
	for(int i=sz-1;i>=0;i--)
	{
		if(s[i]=='D')
		n*=3;
		else if(s[i]=='U')
		{
			if((3*n-2)%4)
			return 0;
			n=(3*n-2)/4;
		}
		else
		{
			if((3*n+1)%2)
			return 0;
			n=(3*n+1)/2;
		}
	}
	return n;
}
int main()
{
	ll sz,i;
	for(sz=0;s[sz]!='\0';sz++);
	for(i=1;solve(i,sz)<LIMIT;i++);
	//if(solve(i,sz))
	printf("%lld %lld\n",i,solve(i,sz));
	//solve(i,sz)<LIMIT
}
