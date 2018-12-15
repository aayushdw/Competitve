#include<stdio.h>
#define for(p,x,y) for(p=x;p<=y;p++)
#define ll long long int
ll num=0;
bool check(ll a)
{
	if (a<0||a>9)
	return false;
	return true;
}
int solve(ll p,ll q,ll r,ll s)
{
	ll a,b,c,d,count=0;
	for(a,0,9)
	{
		if(check(b=p-a))
		if(check(c=q-a))
		if(check(d=r-b))
		if(c+d==s)
		count++;
	}
	return count;
}
int main()
{
	ll i[8]={0},sum,a,b;
	for(i[0],0,9)
	for(i[1],0,9)
	for(i[2],0,9)
	for(i[3],0,9)
	for(i[4],0,9)
	for(i[5],0,9)
	for(i[6],0,9)
	{
		sum=i[0]+i[1]+i[2]+i[3];
		i[7]=sum-i[4]-i[5]-i[6];
		if(!check(i[7]))
		continue;
		a=solve(sum-i[0]-i[7],sum-i[1]-i[5],sum-i[2]-i[6],sum-i[3]-i[4]);
		b=solve(sum-i[0]-i[4],sum-i[1]-i[6],sum-i[2]-i[5],sum-i[3]-i[7]);
		num+=a*b;
	}
	printf("%lld",num);
}
