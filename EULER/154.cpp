#include<stdio.h>
#define LIMIT 200000
#define MAX LIMIT+5
#define ll long long int
ll a[MAX][2];
ll powFact(ll n,ll p)
{
	ll count=0,q=p;
	while(n/q)
	{
		count+=n/q;
		q*=p;
	}
	return count;
}
int main()
{
	ll i,j,k,x,y,count=0;
	for(i=0;i<MAX;i++)
	{
		a[i][0]=powFact(i,2);
		a[i][1]=powFact(i,5);
	}
	for(i=0;i<=LIMIT;i++){
		if(i%200==0)
		printf("%lld\n",i);
	for(j=0;j<=LIMIT;j++)
	{
		k=LIMIT-i-j;
		if(k<0)
		continue;
		x=a[LIMIT][0]-a[i][0]-a[j][0]-a[k][0];
		y=a[LIMIT][1]-a[i][1]-a[j][1]-a[k][1];
		if(x>11&&y>11)
		count++;
	}
	}
	printf("%lld",count);
}

