#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define sc(x) scanf("%d",&x);
int getSum(int *st,int start,int end,int qs,int qe,int index)
{
	if(qs<=start&&qe>=end)
	return st[index];
	if(end<qs||start>qe)
	return 0;
	int mid=start+(end-start)/2;
	return getSum(st,start,mid,qs,qe,2*index+1)+getSum(st,mid+1,end,qs,qe,2*index+2);
}
void updateValue(int *st,int start,int end,int i,int diff,int index)
{
	if(i<start||i>end)
	return;
	st[index]+=diff;
	if(start!=end)
	{
		int mid=start+(end-start)/2;
		updateValue(st,start,mid,i,diff,2*index+1);
		updateValue(st,mid+1,end,i,diff,2*index+2);
	}
}
int constructSTree(int a[],int start,int end,int *st,int si)
{
	if(start==end)
	{
		st[si]=a[start];
		return a[start];
	}
	int mid=start+(end-start)/2;
	st[si]=constructSTree(a,start,mid,st,2*si+1)+constructSTree(a,mid+1,end,st,2*si+2);
	return st[si];
}
int *constructST(int a[],int n)
{
	int x=(int)(ceil(log2(n)));
	int sz=2*(int)pow(2,x)-1;
	int *st=(int*)calloc(sz,sizeof(int));
	constructSTree(a,0,n-1,st,0);
	return st;
}
void findNum(int *st,int n)
{
	int a,b,sum;
	sc(a); sc(b);
	sum=getSum(st,0,n-1,a,b,0);
	printf("%d\n",sum);
	return;
}
void update(int *st,int n)
{
	int i,diff;
	sc(i); sc(diff);
	updateValue(st,0,n-1,i,diff,0);
}
int main()
{
	int n,i,q;
	char s[10];
	sc(n); sc(q);
	int a[n];
	for(i=0;i<n;i++)
	a[i]=0;
	int *st=constructST(a,n);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='f')
		findNum(st,n);
		else if(s[0]=='a')
		update(st,n);
	}
}
