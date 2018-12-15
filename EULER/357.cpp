#include<math.h>
#include<vector>
#include<stdio.h>
#include<bitset>
#define ll long long int
#define MAX 10000000
using namespace std;
bitset<MAX> t;
ll primes[5761460],count;
void seive()
{
	ll i=2,j;
	t[0]=1; t[1]=1;
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
	count=j;
	return;
}
bool check(vector<pair<ll,ll> > v, ll index,ll num,ll n)
{
	if(index==v.size())
	return 1;
	ll i;
	bool f=1;
	f=f&&check(v,index+1,num,n);
	for(i=1;i<=v[index].second;i++)
	{
		num*=v[index].first;
		//printf("%lld ",num);
		if(t[num+n/num])
		f=0;
		f=(f&&check(v,index+1,num,n));
		if(!f)
		return f;
	}
	return f;
}
bool solve(ll n)
{
	ll i=0,c,p,x=n;
	vector<pair<ll,ll> > v;
	while(n>1)
	{
		c=0; p=primes[i];
		while(n%p==0)
		{
			n/=p;
			c++;
		}
		if(c>1)
		return 0;
		else if(c==1)
		v.push_back(make_pair(p,c));
		i++;
	}
	//printf("x=%lld\n",x);
	return check(v,0,1,x);
}
int main()
{
	ll i,j,sum=0;
	seive();
	for(i=0;i<count;i++)
	{
		/*if(i%10000==0)
		printf("%lld\n",i);*/
		if(!t[2+(primes[i]-1)/2])
		{
			if(solve(primes[i]-1))
			sum+=primes[i]-1;
		}
	}
	printf("%lld\n",sum);
}
