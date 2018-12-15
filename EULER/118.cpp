#include<math.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<bitset>
typedef long long ll;
using namespace std;
ll c=0;

 
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

void check(ll *arr,ll sz,ll m)
{
	if(sz==0)
	{
		c++;
		return;
	}
	ll i=0,p=0;
	while(i<sz)
	{
		p*=10;
		p+=arr[i];
		i++;
		//printf("%lld %lld %lld-> ",*arr,sz,m);
		//printf("i=%lld p=%lld\n",i,p);
		if(p>m&&judge(p))
		check(arr+i,sz-i,p);
	}
}
int main()
{
	ll i,j;
	ll *arr;
	arr=(ll*)malloc(9*sizeof(ll));
	/*a[0]=2; a[1]=5; a[2]=4; a[3]=7; a[4]=8; a[5]=9; a[6]=6; a[7]=3; a[8]=1;
	check(a,9,1);*/
	for(i=0;i<9;i++)
	arr[i]=i+1;
	//arr[0]=2;arr[1]=1;
	//check(arr,9,1);
	ll f=0;
	do
	{
		check(arr,9,1);
		f++;
	} while(next_permutation(arr,arr+9));
	printf("%lld",c);
}
