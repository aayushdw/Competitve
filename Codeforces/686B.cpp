#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
ll b7(ll p)
{
	ll c=0;
	while(p)
	{
		p/=7;
		c++;
	}
	return c;
}
bool check(ll c[],ll n1,ll n2,ll n,ll m)
{
	ll a=0,b=0,x,i;
	for(i=0;i<n1;i++)
	{
		x=c[i];
		a*=7;
		a+=x;
	}
	if(a>=n)
	return false;
	for(i=n1;i<n2+n1;i++)
	{
		x=c[i];
		b*=7;
		b+=x;
	}
	if(b>=m)
	return false;
	a=0;
	for(i=0;i<n1;i++)
	{
		x=c[i];
		printf("%lld",x);
	}
	b=0;
	printf(" ");
	for(i=n1;i<n2+n1;i++)
	{
		x=c[i];
		printf("%lld",x);
	}
	printf("\n");
	return true;
}
int main()
{
	ll n,m,n1,n2,p,i,q=-5,c=0,z;
	scll(n); scll(m);
	p=b7(n-1)+b7(m-1);
	n1=b7(n-1); n2=b7(m-1);
	if(p>7||(n==1&&m==1))
	{
		printf("0");
		return 0;
	}
	ll a[7],b[7];
	for(i=0;i<7;i++)
	{
		a[i]=i;
		b[i]=6-i;
	}
	while(1)
	{
		bool f=true;
		for(i=0;i<7;i++)
		if(a[i]!=b[i])
		f=false;
		if(f)
		break;
		z=0;
		for(i=0;i<p;i++)
		{
			z*=10;
			z+=a[i];
		}
		if(z!=q)
		{
			q=z;
			if(check(a,n1,n2,n,m))
			{
				c++;
				//printf("%lld\n",q);
			}
		}
		next_permutation(a,a+7);
	}
	printf("%lld",c);
	return 0;
}
