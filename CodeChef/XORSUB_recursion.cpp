#include<stdio.h>
#define sc(x) scanf("%d",&x)
int max(int a,int b)
{
	if(a>b)
	return a;
	return b;
}
int bitXOR(int a,int b)
{
	int x=(a&b);
	int y=(~a&~b);
	return (~x&~y);
}
int xorsub(int arr[],int n,int index,int currXor)
{
	if(index==n)
	return currXor;
	int k=bitXOR(currXor,arr[index]);
	return max(xorsub(arr,n,index+1,k),xorsub(arr,n,index+1,currXor));
}
int main()
{
	int t,n,a,i;
	sc(t);
	while(t--)
	{
		sc(n); sc(a);
		int arr[n];
		for(i=0;i<n;i++)
		sc(arr[i]);
		printf("%d\n",xorsub(arr,n,0,a));
	}
	return 0;
} 
