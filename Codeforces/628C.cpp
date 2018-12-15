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
#define MAX 100000+5
using namespace std;
char s[MAX];
int arr[MAX],arr1[MAX];
int way(int a,int b)
{
	return a>b?1:0;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,k,i,sum=0;
	sc(n); sc(k);
	getchar();
	for(i=0;i<n;i++)
	{
		s[i]=getchar();
		arr[i]=way(s[i]-'a','z'-s[i]);
		arr1[i]=max(s[i]-'a','z'-s[i]);
		sum+=arr1[i];
	}
	if(sum<k)
	printf("-1");
	else
	{
		for(i=0;i<n;i++)
		{
			if(k>=arr1[i])
			{
				if(arr[i])
				printf("%c",s[i]-arr1[i]);
				else
				printf("%c",s[i]+arr1[i]);
				k-=arr1[i];
			}
			else
			{
				if(s[i]+k<='z')
				printf("%c",s[i]+k);
				else
				printf("%c",s[i]-k);
				k=0;
			}
		}
	}
	return 0;
}
