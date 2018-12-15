#include<stdio.h>
#include<math.h>
#define ll long long int
#define MAX (1000000000000)/2
int main()
{
	ll arr[42]={MAX};
	ll j,i=1,p=2;
	while(arr[i-1])
	{
		arr[i]=MAX/p;
		//printf("%lld\n",arr[i]);
		i++;
		p*=2;
	}
	for(j=0;j<i;j++)
	arr[j]=arr[j]-arr[j+1];
	ll ans=0;
	for(j=0;j<i;j++)
	{
		ans+=j*arr[j];
		printf("%lld %lld\n",j,arr[j]);
	}
	printf("%lld\n",ans+ans*904961);
}
