#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#define ll long long int
#define NUM 18
using namespace std;
set<pair<ll,ll> > s[19];
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main()
{
	s[1].insert(make_pair(1,1));
	s[0].insert(make_pair(1,1));
	ll x,y,a,b,p,q,j,k;
	typeof(s[0].begin()) it1,it2;
	for(ll i=2;i<=NUM;i++)
	{
		printf("%lld\n",i);
		for(j=1;j<=i/2;j++)
		{
			if(i==NUM)
			printf("%lld\n",j);
			k=i-j;
			for(it1=s[j].begin();it1!=s[j].end();it1++)
			for(it2=s[k].begin();it2!=s[k].end();it2++)
			{
				x=it1->first; y=it1->second;
				p=it2->first; q=it2->second;
				a=gcd(x*q+p*y,q*y);
				b=gcd(x*q+p*y,p*x);
				if(x*q+p*y<=0||q*y<=0||p*x<=0)
				{
					printf("OVERFLOW");
					return 0;
				}
				s[i].insert(make_pair((x*q+p*y)/a,q*y/a));
				s[i].insert(make_pair(p*x/b,(x*q+p*y)/b));
				s[0].insert(make_pair((x*q+p*y)/a,q*y/a));
				s[0].insert(make_pair(p*x/b,(x*q+p*y)/b));
			}
		}
	}
	printf("%lld",s[0].size());
}
