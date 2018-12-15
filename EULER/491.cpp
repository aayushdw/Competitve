#include<stdio.h>
#include<math.h>
#define ll long long int
ll fact[12]={1};
void pre()
{
	for(ll i=1;i<12;i++)
	fact[i]=fact[i-1]*i;
	return;
}
void getBase3(ll n,ll a[])
{
	ll i=0;
	while(n)
	{
		a[i++]=n%3;
		n/=3;
	}
	return;
}
bool check(ll a[])
{
	ll i,sum=0;
	for(i=0;i<10;i++)
	sum+=a[i];
	if(sum==10)
	return true;
	return false;
}
bool div(ll a[])
{
	ll i,sum=0;
	for(i=0;i<10;i++)
	sum+=i*a[i];
	if((90-2*sum)%11)
	return false;
	return true;
}
ll ways(ll a[])
{
	ll tot=0,i,way;
	for(i=0;i<10;i++)
	tot+=a[i];
	way=fact[tot];
	for(i=0;i<10;i++)
	way/=fact[a[i]];
	return way;
}
ll solve(ll a[])
{
	if(!check(a))
	return 0;
	if(!div(a))
	return 0;
	ll i,x=0,y=0;
	if(a[0])
	{
		for(i=1;i<10;i++)
		{
			if(a[i])
			{
				a[i]--;
				x+=ways(a);
				a[i]++;
			}
		}
	}
	else
	x=ways(a);
	for(i=0;i<10;i++)
	a[i]=2-a[i];
	y=ways(a);
	return x*y;
	return x;
}
int main()
{
	ll i,j,limit=pow(3,10),a[10]={0},num=0;
	pre();
	for(i=1;i<=limit;i++)
	{
		for(j=0;j<10;j++)
		a[j]=0;
		getBase3(i,a);
		num+=solve(a);
	}
	printf("%lld",num);
}
