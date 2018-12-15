#include<stdio.h>
#include<math.h>
typedef long long int ll;
void fun(ll a[],ll p,ll index,ll n)
{
	if(index==p)
	return;
	ll k=p-index;
	a[index]=1;
	if(n<=pow(2,k-1))
	a[index]=0;
	n-=a[index]*pow(2,k-1);
	fun(a,p,index+1,n);
	return;
}
int main()
{
	ll n,p,i,t;
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%lld",&n);
	for(p=1;;p++)
	if(pow(2,p+1)-2>=n)
	break;
	ll a[p]; i=0;
	n-=pow(2,p)-2;
	fun(a,p,0,n);
	for(i=0;i<p;i++)
	printf("%d",a[i]+5);
	printf("\n");
	}
	return 0;
}
