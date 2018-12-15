#include<stdio.h>
#include<set>
#define ll long long int
using namespace std;
bool check(ll p)
{
	while(p)
	{
		if((p%10)-2>0)
		return false;
		p/=10;
	}
	return true;
}
int main()
{
	ll i;
	for(i=1;!check(i*999);i++)
	if(i*99<0)
	{
		printf("ERROR");
		return 0;
	}
	printf("%lld",i);
}
