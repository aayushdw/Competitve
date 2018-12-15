#include<stdio.h>
#define ll long long int
#define MAX 50000000
ll arr[MAX]={0};
int main()
{
	ll u,v;
	for(u=1;u<MAX;u++)
	{
		for(v=1;u*v<MAX;v++)
		{
			if((u+v)%4==0 && 3*v>u && (3*v-u)%4==0)
			arr[u*v]++;
		}
	}
	ll i,count=0;
	for(i=0;i<MAX;i++)
	if(arr[i]==1)
	count++;
	printf("%lld\n",count);
}
