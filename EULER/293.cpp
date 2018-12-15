#include<stdio.h>
#include<math.h>
#include<bitset>
#include<vector>
#include<set>
typedef long long ll;
#define LIMIT 1000000000
#define MAX 1000
using namespace std;
bitset<MAX> t=false;
ll primes[300],count;
int T;
ll mod;
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll a[]={1996011519951206ll,1995120619960115ll,1995100319960115ll,195100319951206ll,1996011519951003ll};
 
 
ll multi(ll x,ll y)
{
	ll w=x*y-mod*(ll(double(x)*y/mod+1e-3));
	while(w<0)
		w+=mod;
	while(w>=mod)
		w-=mod;
	return w;
}
 
ll pow(ll x,ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
			t=multi(t,x);
		x=multi(x,x);
		y>>=1;
	}
	return t;
}
 
bool judge(ll n)
{
	if(n==2) return true;
	if(n<2||!(n&1)) return false;
	for(int i=0;i<25;i++)
		if(n%b[i]==0&&n!=b[i])
			return false;
	mod=n;
	int t=0;
	ll u=n-1;
	while(!(u&1)) t++,u>>=1;
	for(int i=0;i<5;i++)
	{
		ll x=a[i]%(n-1)+1;
		x=pow(x,u);
		ll y=x;
		for(int j=1;j<=t;j++)
		{
			x=multi(x,x);
			if(x==1&&y!=1&&y!=n-1)
				return false;
			y=x;
		}
		if(x!=1) return false;
	}
	return true;
}
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
			t[i*j]=true;
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
int main()
{
	t[0]=true;
	t[1]=true;
	seive();
	printf("seive done\n");
	ll i,j,sum=0,count=0;
	vector<pair<ll,ll> > v1,v2;
	set<ll> s;
	v1.push_back(make_pair(2,0));
	while(v1.size())
	{
		count+=v1.size();
		for(i=0;i<v1.size();i++)
		{
			for(j=2;;j++)
			if(judge(v1[i].first+j))
			{
				s.insert(j);
				break;
			}
			if(primes[v1[i].second]*v1[i].first<LIMIT)
			v2.push_back(make_pair(primes[v1[i].second]*v1[i].first,v1[i].second));
			if(primes[v1[i].second+1]*v1[i].first<LIMIT)
			v2.push_back(make_pair(primes[v1[i].second+1]*v1[i].first,v1[i].second+1));
		}
		v1.clear();
		v1=v2;
		v2.clear();
	}
	//return 0;
	typeof(s.begin()) it;
	for(it=s.begin();it!=s.end();it++)
	sum+=*it;
	printf("%lld\n",*it);
	printf("%lld %lld",count,sum);
}
