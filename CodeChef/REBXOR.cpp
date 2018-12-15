#include<stdio.h>
#define sc(x) scanf("%d",&x)
#define MAX 100005
int a[MAX]={0},b[MAX]={0},arr1[MAX][2]={0},arr2[MAX][2]={0},max1[MAX]={0},max2[MAX]={0};
int bitXOR(int a,int b)
{
	int x=(a&b);
	int y=(~a&~b);
	return (~x&~y);
}
void get(int ar[],int arr[MAX][2],int max[],int n)
{
	int l,i;
	arr[1][0]=ar[0]; arr[1][1]=ar[0];
	for(l=2;l<n;l++)
	{
		arr[l][0]=bitXOR(arr[l-1][0],ar[l-1]);
		arr[l][1]=arr[l][0];
	}
	for(i=1;i<n;i++)
	{
		for(l=1;l<=i;l++)
		{
			arr[l][0]=bitXOR(bitXOR(arr[l][0],ar[i-1]),ar[i-l-1]);
			if(arr[l][0]>arr[l][1])
			arr[l][1]=arr[l][0];
			if(arr[l][1]>max[i])
			max[i]=arr[l][1];
		}
	}
	return;
}
int main()
{
	int n,i,k;
	sc(n);
	for(i=0;i<n;i++)
	{
		sc(a[i]);
		b[n-i-1]=a[i];
	}
	max1[1]=a[0];
	max2[1]=b[0];
	get(a,arr1,max1,n);
	get(b,arr2,max2,n);
	int max=0;
	for(i=1;i<n;i++)
	{
		k=max1[i]+max2[n-i];
		if(k>max)
		max=k;
	}
	printf("%d",max);
	return 0;
}
