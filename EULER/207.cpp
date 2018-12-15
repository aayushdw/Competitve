#include<stdio.h>
#include<math.h>
#define ll long long int
bool check1(ll p)
{
	ll q=p;
	while(p%2==0)
	p/=2;
	if(p!=1)
	return 0;
	//printf("%d\n",q);
	return 1;
}
ll check(ll k)
{
	ll p=4*k+1,a;
	double q=sqrt(p);
	a=(int)q;
	if(a*a!=p||(a+1)%2!=0)
	return 0;
	if(check1((a+1)/2))
	return 1;
	return 2;
}
int main()
{
	ll k,count1=0,count2=0;
	//printf("%d",check(6));
	for(k=2;;k+=2)
	{
		if(check(k)==1)
		{
			count1++;
			//printf("integer %d %d\n",k%4,k/4);
		}
		else if(check(k)==2)
		{
			count2++;
			//printf("real %d %d\n",k%4,k/4);
		}
		if(k%10000000==0)
		printf("%lld %0.12lf\n",k,count1*1.0/(count2+count1));
		if(count1*1.0/(count2+count1)<1.0/12345)
		{
			printf("%lld",k);
			return 0;
		}
	}
}
