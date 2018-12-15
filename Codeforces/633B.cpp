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
#define MAX 500000+5
using namespace std;
int a[MAX]={0};
int count_5(int n)
{
	int c=0;
	while(n%5==0)
	{
		n/=5;
		c++;
	}
	return c;
}
int main()
{
	int i,p,k,n,j;
	for(i=1;i<MAX;i++)
	a[i]=a[i-1]+count_5(i);
	sc(n);
	vector<int> v;
	for(i=1;i<MAX;i++)
	if(a[i]==n)
	v.push_back(i);
	printf("%d\n",v.size());
	for(i=0;i<v.size();i++)
	printf("%d ",v[i]);
	return 0;
}
