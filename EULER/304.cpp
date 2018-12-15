#include<stdio.h>
#include <map>
#define MAX 100000
#define START 100000000000000
#define MOD 1234567891011
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

ll mulmod(ll x, ll y, ll m) {
    ll w=x*y-m*(ll(double(x)*y/m+1e-3));
	while(w<0)
		w+=m;
	while(w>=m)
		w-=m;
	return w;
}

void multiply(ll F[2][2], ll M[2][2]);
 
void power(ll F[2][2], ll n);
 
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n);
  return F[0][0];
}
 
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (mulmod(F[0][0],M[0][0],MOD) + mulmod(F[0][1],M[1][0],MOD))%MOD;
  ll y =  (mulmod(F[0][0],M[0][1],MOD) + mulmod(F[0][1],M[1][1],MOD))%MOD;
  ll z =  (mulmod(F[1][0],M[0][0],MOD) + mulmod(F[1][1],M[1][0],MOD))%MOD;
  ll w =  (mulmod(F[1][0],M[0][1],MOD) + mulmod(F[1][1],M[1][1],MOD))%MOD;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 

int main()
{
	ll i,j,sum=0;
	//printf("%lld",fib(2));
	for(i=START+1,j=0;j<MAX;i+=2)
	{
		if(judge(i))
		{
			//printf("%lld\n",i);
			sum+=fib(i-1);
			sum%=MOD;
			j++;
			if(j%1000==0)
			printf("%lld\n",j);
		}
	}
	printf("%lld %lld\n",sum,sum+MOD);
}
