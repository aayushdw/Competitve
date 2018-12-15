#include<stdio.h>
#define MOD 1000000007
#define MAX 100
#define ll long long int
int main()
{
	ll arr[MAX+1]={1},i,j;
	for(i=1;i<MAX+1;i++)
	{
		for(j=i;j<MAX+1;j++)
		{
			arr[j]+=arr[j-i];
			arr[j]%=MOD;
		}
	}

	for(i=0; i<=MAX ; i++)
	{
		printf("%lld %lld\n",i,arr[i]);
	}

	//printf("%lld",arr[MAX]);
	return 0;
}
