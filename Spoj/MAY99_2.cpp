#include<stdio.h>
typedef long long int ll;
ll pow(ll a,ll b)
{
	if(b==0)
	return 1;
	if(a==0)
	return 0;
	ll k=1;
	while(b--)
	k*=a;
	return k;
}
void fun(ll a[],ll p,ll index,ll n)
{
	if(index==p)
	return;
	ll k=p-index;
	if(pow(5,k)<0)
	printf("kakjf");
	if(n<=pow(5,k-1))
	a[index]=0;
	else if(n<=2*pow(5,k-1))
	a[index]=1;
	else if(n<=3*pow(5,k-1))
	a[index]=2;
	else if(n<=4*pow(5,k-1))
	a[index]=3;
	else if(n<=5*pow(5,k-1))
	a[index]=4;
	n-=a[index]*pow(5,k-1);
	fun(a,p,index+1,n);
	return;
}
int main()
{
	ll n,p,i,t;
	char s[5]={'m','a','n','k','u'};
	scanf("%lld",&t);
	while(t--)
	{
	scanf("%lld",&n);
	for(p=1;;p++)
	if((pow(5,p+1)-5)/4>=n)
	break;
	ll a[p]; i=0;
	n-=(pow(5,p)-5)/4;
	fun(a,p,0,n);
	for(i=0;i<p;i++)
	printf("%c",s[a[i]]);
	printf("\n");
	}
	return 0;
}
