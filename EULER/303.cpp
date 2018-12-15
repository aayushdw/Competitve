#include<stdio.h>
#include<set>
#define ll long long int
using namespace std;
ll nextNum(ll p)
{
	ll mul=1,num=0;
	while(p)
	{
		num+=mul*(p%3);
		p/=3;
		mul*=10;
	}
	return num;
}
int main()
{
	ll i,j,sum=0,n;
	set<int> s,v;
	typeof(s.begin()) it;
	for(i=1;i<=10000;i++)
	s.insert(i);
	for(i=1;!s.empty();i++)
	{
		n=nextNum(i);
		if(n<0){
		printf("OVERFLOW");
		return 0;
		}
		for(it=s.begin();it!=s.end();it++)
		{
			if(n%(*it))
			continue;
			if((*it)%9==0)
			printf("%lld-> %lld %lld\n",(*it),n,n/(*it));
			sum+=n/(*it);
			v.insert(*it);
			
		}
		for(it=v.begin();it!=v.end();it++)
		s.erase(*it);
		v.clear();
		if(s.size()==1)
		{
		
		printf("%lld %lld\n",sum,*s.begin());
		return 0;
		}
		
	}
	printf("%lld",sum);
}
