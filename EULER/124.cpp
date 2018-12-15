#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define pb push_back
#define mp make_pair
#define MAX 100000
using namespace std;
bool t[MAX]={1,1,0};
ll primes[10000],num;
void seive()
{
	ll i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	j=0;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	num=j;
	return;
}
int main()
{
	seive();
	ll i,j;
	vector <pair<ll,ll> > v;
	v.pb(mp(INT_MAX,INT_MAX));
	for(i=1;i<=MAX;i++)
	v.pb(mp(1,i));
	for(j=0;j<num;j++)
	{
		for(i=1;primes[j]*i<=MAX;i++)
		(v[primes[j]*i].first)*=primes[j];
	}
	/*for(i=0;i<=MAX;i++)
	printf("%lld -> %lld %lld\n",i,v[i].first,v[i].second);
	printf("\n");*/
	sort(v.begin(),v.end());
	/*for(i=0;i<=MAX;i++)
	printf("%lld -> %lld %lld\n",i,v[i].first,v[i].second);*/
	//printf("%lld %lld %lld %lld",v[0].first,v[0].second,v[9999].first,v[9999].second);
	printf("ANS=%lld\n",v[9999].second);
}










