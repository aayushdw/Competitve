#include<stdio.h>
#include<vector>
#include<map>
#include<limits.h>
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
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
ll giveMin(ll a[],ll n)
{
	ll sum,i,p,j;
	sum=0;
	for(i=0;i<n;i++)
	sum+=a[i];
	ll arr[sum+1],m=0,nm=0;
	for(i=0;i<=sum;i++)
	arr[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=m;j>=0;j--)
		{
			if(!arr[j])
			continue;
			arr[j+a[i]]=1;
			nm=max(nm,j+a[i]);
		}
		arr[a[i]]=1;
		nm=max(nm,a[i]);
		m=nm;
	}
	m=INT_MAX;
	for(i=0;i<=sum;i++)
	{
		if(!arr[i])
		continue;
		p=sum-2*i;
		if(p<0)
		p*=-1;
		m=min(m,p);
	}
	return m;
}
int main()
{
	ll t,n,ai,bi,i,p;
	char c;
	scll(t);
	while(t--)
	{
		scll(n);
		ll a[(n+1)-(n+1)/2],b[(n+1)/2];
		for(i=0;i<2*n+1;i++)
		{
			if(i%2==0)
			{
				scll(p);
				if(i%4==0)
				a[i/4]=p;
				else
				b[i/4]=p;
			}
			else
			{
				getchar();
				c=getchar();
			}
		}
		/*for(i=0;i<(n+1)-(n+1)/2;i++)
		printf("%lld ",a[i]);
		printf("\n");
		for(i=0;i<(n+1)/2;i++)
		printf("%lld ",b[i]);
		printf("\n");*/
		if(n<=2)
		{
			printf("NO\n");
			continue;
		}
		ll ans=giveMin(a,(n+1)-(n+1)/2)+giveMin(b,(n+1)/2);
		printf("%lld\n",ans);
		
	}
}
