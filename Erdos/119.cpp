#include<stdio.h>
#include<limits.h>
#include<vector>
#define MAX 1000000+5
#define ll long long int 
using namespace std;
ll arr[MAX]={0},pow[100+5]={0};
int main()
{
	ll i,j,k,sum=0;
	vector<ll> v[2];
	for(i=0;i<MAX;i++)
	arr[i]=INT_MAX;
	i=1;
	while(i*i*i<MAX)
	{
		arr[i*i*i]=1;
		pow[i]=i*i*i;
		v[0].push_back(i*i*i);
		i++;
	}
	for(i=1;i<MAX;i++)
	{
		if(i%10000==0)
		printf("%lld\n",i);
		v[i%2].resize(0);
		for(vector<ll>::iterator it = v[!(i%2)].begin(); it != v[!(i%2)].end(); it++)
		{
				k=1;
				while(pow[k]+(*it)<MAX)
				{
					if(arr[*it]+1<arr[(*it)+pow[k]])
					{
						arr[(*it)+pow[k]]=arr[*it]+1;
						v[i%2].push_back((*it)+pow[k]);
					}
					k++;
				}
		}
	}
	for(i=1;i<=1000000;i++)
	sum+=arr[i];
	printf("%lld",sum);
	//printf("%d %d %d",arr[2],arr[9],arr[17]);
}
