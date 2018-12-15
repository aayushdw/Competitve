#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
#define prll(x) printf("%I64d",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 300000+5
char a[25][25];
using namespace std;
int check(int n,char arr[],int k)
{
	if(n<=0)
	return 0;
	int count=0,i;
	int v[25]={0};
	for(i=0;i<n;i++)
	{
		if(arr[i]=='O')
		count=0;
		else if(arr[i]=='X')
		count++;
		else
		{
			v[i]=count;
			count=0;
		}
	}
	count=0;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]=='O')
		count=0;
		else if(arr[i]=='X')
		count++;
		else
		{
			v[i]+=count;
			count=0;
		}
	}
	for(i=0;i<n;i++)
	if(v[i]+1>=k)
	return 1;
	return 0;
}
int main()
{
	int t,n,k,i,j,f;
	char arr[25];
	sc(t);
	while(t--)
	{
		sc(n); sc(k); getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			a[i][j]=getchar();
			getchar();
		}
		f=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			arr[j]=a[i][j];
			f=max(f,check(n,arr,k));
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			arr[j]=a[j][i];
			f=max(f,check(n,arr,k));
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			arr[j]=a[i][j];
			f=max(f,check(n-i,arr,k));
		}
		for(j=0;j<n;j++)
		{
			for(i=0;i<n-j;i++)
			arr[i]=a[i][j];
			f=max(f,check(n-j,arr,k));
		}
		f=max(f,check(n,arr,k));
		if(f)
		printf("YES");
		else
		printf("NO");
	}
	return 0;
}
