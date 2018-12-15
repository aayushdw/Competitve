#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 18
#define ll long long int
using namespace std;
ll f[MAX+1]={1};
void pre()
{
	ll i;
	for(i=1;i<MAX+1;i++)
	f[i]=f[i-1]*i;
}
ll ways(ll arr[])
{
	ll i,sum=0,ans;
	for(i=0;i<10;i++)
	sum+=arr[i];
	ans=f[sum];
	for(i=0;i<10;i++)
	ans/=f[arr[i]];
	return ans;
}
ll ways0(ll arr[])
{
	ll ans=ways(arr);
	ll a[10];
	for(ll i=0;i<10;i++)
	a[i]=arr[i];
	a[0]--;
	return ans-ways(a);
}
int main()
{
	pre();
	ll i,j,k,l,p,num=0,arr[10];
	for(i=0;3*i<=MAX;i++)
	for(j=0;3*i+2*j<=MAX;j++)
	{
		k=MAX-3*i-2*j;
		if(i+j+k>10)
		continue;
		l=10-i-j-k;
		printf("%lld %lld %lld\n",k,2*j,3*i);
		for(p=0;p<l;p++)
		arr[p]=0;
		for(;p<k+l;p++)
		arr[p]=1;
		for(;p<j+k+l;p++)
		arr[p]=2;
		for(;p<i+j+k+l;p++)
		arr[p]=3;
		do{
			if(!arr[0])
			num+=ways(arr);
			else
			num+=ways0(arr);
		}	while(next_permutation(arr,arr+10));
	}
	printf("%lld\n",num);
}
