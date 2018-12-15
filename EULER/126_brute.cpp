#include<stdio.h>
#define MAX 50
int arr[MAX]={0};
int main()
{
	int a,b,c,i;
	for(a=1;a<MAX;a++)
	for(b=1;2*a*b<MAX&&b<=a;b++)
	for(c=1;2*a*b+2*a*c+2*b*c<MAX&&c<=b;c++)
	arr[2*a*b+2*b*c+2*a*c]++;
	//printf("%lld %lld %lld\n",a,b,c);
	for(i=0;i<MAX;i++)
	printf("%lld %lld\n",i,arr[i]);
}
