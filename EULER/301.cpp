#include<stdio.h>
int main()
{
	long long int count=0;
	for(int i=1;i<=(1<<30);i++)
	{
		//printf("%d\n",i);
		if(!(i^(2*i)^(3*i)))
		count++;
	}
	printf("%lld\n",count);
}
