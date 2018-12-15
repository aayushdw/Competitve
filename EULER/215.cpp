#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
ll C[50][50],ways[50][3400]={0};
using namespace std;
vector< vector<ll> > v(3400),v1(3400),arr(3400);
bool check(ll a,ll b)
{
	ll i,j;
	for(i=0;i<v1[a].size()-1;i++)
	for(j=0;j<v1[b].size()-1;j++)
	if(v1[a][i]==v1[b][j])
	return false;
	return true;
}
void pre()
{
	ll i,j;
	for(i=0;i<50;i++)
	for(j=0;j<50;j++)
	if(j==0||i==j)
	C[i][j]=1;
	else
	C[i][j]=C[i-1][j-1]+C[i-1][j];
	return;
}
int main()
{
	pre();
	ll p=32,q=10,i,j,count=0;;
	for(i=0;i<=p/3;i++)
	{
		j=(p-3*i)/2;
		if(3*i+2*j!=p)
		continue;
		//printf("%lld %lld\n",i,j);
		//count+=C[i+j][i];
		//printf("%lld\n",count);
		ll a[30];
		for(ll k=0;k<j;k++)
		a[k]=2;
		for(ll k=j;k<i+j;k++)
		a[k]=3;
		do
		{
			for(ll k=0;k<i+j;k++)
			v[count].pb(a[k]);
			count++;
		} while(next_permutation(a,a+i+j));
	}
	for(i=0;i<count;i++)
	{
		v1[i].pb(v[i][0]);
		for(j=1;j<v[i].size();j++)
		v1[i].pb(v1[i][j-1]+v[i][j]);
	}
	for(i=0;i<count;i++)
	for(j=i+1;j<count;j++)
	if(check(i,j))
	{
		arr[i].pb(j);
		arr[j].pb(i);
	}
	
	for(i=0;i<count;i++)
	ways[0][i]=1;
	for(i=1;i<q;i++)
	{
		for(j=0;j<count;j++)
		{
			for(ll k=0;k<arr[j].size();k++)
			ways[i][arr[j][k]]+=ways[i-1][j];
		}
	}
	
	ll sum=0;
	for(i=0;i<count;i++)
	sum+=ways[q-1][i];
	printf("%lld",sum);
	return 0;
}
