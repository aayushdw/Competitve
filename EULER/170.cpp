#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define ll long long int
using namespace std;
void split(ll p,ll *a)
{
	for(ll i=0;i<10;i++)
	a[i]=0;
	while(p)
	{
		a[p%10]++;
		p/=10;
	}
	return;
}
bool check(ll *a,ll m,ll sz,ll *b)
{
	if(sz<=0)
	return true;
	if(!a[0])
	return false;
	/*printf("sz=%lld\n",sz);
	for(ll j=0;j<10;j++)
	printf("%lld",j);
	printf("\n");
	for(ll j=0;j<10;j++)
	printf("%lld",b[j]);
	printf("\n");*/
	ll *c,*d,i;
	bool f,flag=false;
	c=(ll*)malloc(10*sizeof(ll));
	d=(ll*)malloc(10*sizeof(ll));
	for(i=0;i<10;i++)
	c[i]=b[i];
	ll p=0,q,j;
	for(i=0;i<sz;i++)
	{
		p*=10;
		p+=a[i];
		q=p*m;
		split(q,d);
		/*for(j=0;j<10;j++)
		printf("%lld ",d[j]);
		printf("\n");*/
		f=false;
		for(j=0;j<10;j++)
		if(c[j]+d[j]>1)
		{
			f=true;
			break;
		}
		else
		c[j]+=d[j];
		if(!f)
		{
			if(check(a+i+1,m,sz-i-1,c))
			flag=true;
		}
		for(j=0;j<10;j++)
		c[j]=b[j];
	}
	return flag;
}
int main()
{
	ll i,j,k,*a,*b,f=0;
	a=(ll*)malloc(10*sizeof(ll));
	b=(ll*)malloc(10*sizeof(ll));
	for(i=0;i<10;i++)
	a[i]=i;
	a[0]=1; a[1]=0;
	do{
		for(i=0;i<10;i++)
		b[i]=0;
		/*for(i=0;i<10;i++)
		printf("%lld ",a[i]);
		printf("\n");*/
		if(check(a+1,a[0],9,b))
		{
			for(i=0;i<10;i++)
			printf("%lld ",a[i]);
			printf("\n");
		}
		//f++;
	} while(next_permutation(a,a+10));
}
