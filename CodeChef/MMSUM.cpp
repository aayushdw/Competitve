#include<stdio.h>
#include<vector>
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
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
int main()
{
	ll t,n,i,j;
	scll(t);
	while(t--)
	{
		scll(n);
		ll a[n],b[n],c[n],d[n],p;
		for(i=0;i<n;i++)
		{
			scll(a[i]);
			b[n-1-i]=a[i];
		}
		c[0]=a[0];
		d[0]=b[0];
		for(i=1;i<n;i++)
		{
			c[i]=max(a[i],c[i-1]+a[i]);
			d[i]=max(b[i],d[i-1]+b[i]);
		}
		for(i=0;i<n/2;i++)
		{
			p=d[i];
			d[i]=d[n-1-i];
			d[n-1-i]=p;
		}
		ll m=-1000000005;
		for(i=0;i<n-2;i++)
		{
			m=max(m,max(c[i]+d[i+1],c[i]+d[i+2]));
		}
		m=max(m,c[n-2]+d[n-1]);
		printf("%lld\n",m);
	}
	return 0;
}
