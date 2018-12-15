#include<stdio.h>
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
ll s(ll n)
{
	ll i,sum=0,j,k,x,y,p,f,flag,a[5][5];
	for(i=(n*(n-1)/2)+1;i<=((n+1)*n/2);i++)
	{
		if(judge(i))
		{
			p=i-2*n+1;
			for(j=0;j<5;j++)
			for(k=0;k<5;k++)
			a[j][k]=judge(p+(n-2)*j+j*(j-1)/2+k);
			/*
			for(j=0;j<5;j++)
			{
				for(k=0;k<5;k++)
				printf("%lld ",a[j][k]);
				printf("\n");
			}
			*/
			flag=0;
			for(j=1;j<4;j++)
			for(k=1;k<4;k++)
			{
				if(a[j][k])
				{
					f=0;
					for(x=-1;x<2;x++)
					for(y=-1;y<2;y++)
					f+=a[j+x][k+y];
					if(f>=3)
					flag=1;
					//printf("%lld %lld\n",p+(n-2)*j+j*(j-1)/2+k,f);
				}
			}
			if(flag)
			sum+=i;
			//printf("%lld\n",i);
		}
	}
	return sum;
}
int main()
{
	printf("%lld",s(5678027));
}
