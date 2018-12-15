#include<stdio.h>
#include<limits.h>
#define sc(x) scanf("%d",&x)
int max_rating;
void find_max(int a[],int b[],int amount,int n,int index,int rating)
{
	if(index==n)
	return;
	if(amount==0)
	return;
	if(amount>=b[index])
	{
		if(rating-a[index]>max_rating)
		max_rating=rating-a[index];
		find_max(a,b,amount-b[index],n,index+1,rating-a[index]);
		find_max(a,b,amount,n,index+1,rating);
	}
	else
	find_max(a,b,amount,n,index+1,rating);
}
int main()
{
	int t,n,k,m,i,l,r,cost;
	sc(t);
	while(t--)
	{
		sc(n); sc(k); sc(m);
		int c[n+1],d[n+1];
		max_rating=0;
		for(i=1;i<=n;i++)
		{
			sc(c[i]);
			max_rating+=c[i];
			d[i]=INT_MAX;
		}
		while(m--)
		{
			sc(l); sc(r); sc(cost);
			for(i=l;i<=r;i++)
			{
				if(d[i]>cost)
				d[i]=cost;
			}
		}
		int a[n+1],b[n+1],j=0;
		for(i=1;i<=n;i++)
		{
			if(c[i]<0)
			{
				a[j]=c[i];
				b[j++]=d[i];
			}
		}
		find_max(a,b,k,j,0,max_rating);
		printf("%d\n",max_rating);
	}
	return 0;
}
