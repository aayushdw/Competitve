#include<stdio.h>
#include<set>
using namespace std;
#define ll long long int
#define MAX 1000000000000
set<ll> s;
int main()
{
	ll i,p,q,sum=0,count=0;
	typeof(s.begin()) it;
	for(i=2;1+i+i*i<MAX;i++)
	{
		p=1+i+i*i;
		q=i*i*i;
		while(p<MAX)
		{
			s.insert(p);
			p+=q;
			q*=i;
			count++;
		}
	}
	for(it=s.begin();it!=s.end();it++)
	sum++;
	printf("%lld %lld",sum,count);
}
