#include<stdio.h>
#include<set>
#define MAX 1000000000
#define ll long long int
using namespace std;
set<pair<ll,ll> > v;
ll arr[15];
bool isPalin(ll n)
{
	ll size=0,i;
	while(n)
	{
		arr[size++]=n%10;
		n/=10;
	}
	for(i=0;i<size/2;i++)
	if(arr[i]!=arr[size-i-1])
	return false;
	return true;
}
int main()
{
	ll i,j,count=0;
	typeof(v.begin()) it;
	for(i=1;i*i*i<MAX;i++)
	{
		for(j=1;j*j+i*i*i<MAX;j++)
		{
			if(isPalin(i*i*i+j*j))
			{
				bool f=false;
				for(it=v.begin();it!=v.end();it++)
				if((it->first)==i*i*i+j*j)
				break;
				if(it==v.end())
				v.insert(make_pair(i*i*i+j*j,1));
				else
				{
					count=(it->second);
					v.erase(it);
					v.insert(make_pair(i*i*i+j*j,count+1));
				}
			}
		}
	}
	ll sum=0;
	for(it=v.begin();it!=v.end();it++)
	if((it->second)==4)
	{
		sum+=(it->first);
		printf("%lld\n",it->first);
	}
	printf("%lld",sum);
}
