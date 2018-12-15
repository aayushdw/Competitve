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
	ll n,h,k;
	scll(n); scll(h); scll(k);
	ll a[n],i,x;
	for(i=0;i<n;i++)
	scll(a[i]);
	ll p=0,t=0;
	i=0;
	while(i<n)
	{
		while(i<n && p+a[i]<=h)
		{
			p+=a[i];
			i++;
		}
		x=p/k;
		t+=x;
		p-=x*k;
		if(i==n && p)
		{
			p=0;
			t++;
		}
		if(i<n && p+a[i]>h)
		{
			t++;
			p=0;
		}
	}
	prll(t);
	return 0;
}
