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
using namespace std;
char s[MAX];
int arr[MAX];
int main()
{
	gets(s);
	ll len=0,i,count,num;
	while(s[len]!='\0')
	{
		arr[len]=s[len]-'0';
		len++;
	}
	count=0;
	if(arr[0]%4==0)
	count++;
	for(i=1;i<len;i++)
	{
		num=arr[i-1]*10+arr[i];
		if(num%4==0)
		count+=i;
		if(arr[i]%4==0)
		count++;
	}
	prll(count);
	return 0;
}
