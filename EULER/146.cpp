#include<iostream>
#define LIMIT 150000000
using namespace std;

typedef long long ll;
 
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

int main()
{
	ll n,f,sum=0,i;
	for(n=2;n<LIMIT;n+=2)
	{
		if(n%15000000==0)
		printf("%lld\n",n);
		if(judge(n*n+1)&&judge(n*n+3)&&judge(n*n+7)&&judge(n*n+9)&&judge(n*n+13)&&judge(n*n+27))
		{
			f=0;
			for(i=n*n+1;i<=n*n+27;i+=2)
			if(judge(i))
			f++;
			if(f==6)
			sum+=n;
		}
	}
	printf("%lld",sum);
}
