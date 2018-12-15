#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define MAX 30
using namespace std;
vector<pair<ll,ll> > v,v2;
vector<ll> v1;
ll isSquare(ll p)
{
	if(p<0)
	printf("OVERFLOW\n");
	double a=sqrt(p);
	ll q=(ll)a;
	if(q*q==p)
	return q;
	return 0;
}
int main()
{
	ll n,count=0,p,i,x,y,q;
	for(n=1;count<6;n++)
	if(isSquare(5*n*n+14*n+1))
	{
		count++;
		p=isSquare(5*n*n+14*n+1);
		v.push_back(make_pair(n,p));
		v1.push_back(n);
	}
	while(v1.size()<MAX)
	{
		for(i=0;i<v.size();i++)
		{
			x=v[i].first;
			y=v[i].second;
			p=-9*x-4*y-14;
			q=-20*x-9*y-28;
			v2.push_back(make_pair(p,q));
			if(p>0)
			v1.push_back(p);
		}
		v.clear();
		v.insert(v.end(),v2.begin(),v2.end());
		v2.clear();
	}
	sort(v1.begin(),v1.end());
	ll sum=0;
	for(i=0;i<30;i++)
	{
		printf("%3lld\t%lld\n",i+1,v1[i]);
		sum+=v1[i];
	}
	printf("%lld\n",sum);
}
