#include<stdio.h>
int MAX=1000000;
int main()
{
	long long int i,j,count=0,p,k;
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
			count++;
			j+=2;
		}
	}
	printf("%d",count);
	return 0;
}
