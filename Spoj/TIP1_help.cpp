#include<bits/stdc++.h>
bool isPerm(int x,int y)
{
	int a[10]={0}, b[10]={0};
	while(x)
	{
		a[x%10]++;
		x/=10;
	}
	while(y)
	{
		b[y%10]++;
		y/=10;
	}
	for(int i=0;i<10;i++)
	if(a[i]!=b[i])
		return false;
	return true;
}
int phi(int n)
{
	int result=n,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		result-=result/i;
		while(n%i==0)
		n/=i;
	}
	if(n>1)
	result-=result/n;
	return result;
}
int main()
{
	double rmin=1000000.00;
	int n;
	//printf("{");
	for(int i=2;i<100000000;i++)
	{
		n=phi(i);
		if(isPerm(i,n)&& (i*1.0/n)<=rmin )
		{
			printf("%d, %lf\n",i,i*1.0/n);
			rmin=(i*1.0/n);
		}
	}
	//printf("};");
	return 0;
}