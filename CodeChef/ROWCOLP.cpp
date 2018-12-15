#include<stdio.h>
#include<stdlib.h>
#define ll long long int
#define sc(x) scanf("%lld",&x)
#define MOD 1000000007
#define MAX 314170
int main()
{
	ll n,q,a,b,max,i;
	char str[10];
	sc(n); sc(q);
	ll *row, *col;
	row=(ll*)calloc(n,sizeof(ll));
	col=(ll*)calloc(n,sizeof(ll));
	while(q--)
	{
		scanf("%s",str);
		sc(a); sc(b);
		if(str[0]=='R')
		row[a-1]+=b;
		else
		col[a-1]+=b;
	}
	max=0; b=0;
	for(i=0;i<n;i++)
	if(max<row[i])
	max=row[i];
	for(i=0;i<n;i++)
	if(b<col[i])
	b=col[i];
	printf("%lld",max+b);
	return 0;
}
