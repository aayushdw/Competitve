#include<stdio.h>
#define MAX 1000000
int a[MAX+1]={0};
int b[11]={0};
int main()
{
	long long int i,j,p,k,sum=0;
	p=(MAX+8)/4;
	for(i=1;i<p;i++)
	{
		if(i%100000==0)
		printf("%d\n",i);
		if(i%2==0)
		j=2;
		else j=1;
		while(j<i)
		{
			k=i*i-j*j;
			if(k<=MAX)
			a[k]++;
			j+=2;
		}
	}
	for(i=0;i<=MAX;i++)
	{
		if(a[i]>10)
		continue;
		b[a[i]]++;
	}
	for(i=1;i<=10;i++)
	sum+=b[i];
	printf("%lld",sum);
	return 0;
}
