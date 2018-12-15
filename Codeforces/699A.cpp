#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
int main()
{
	ll n,t=INT_MAX;
	char c;
	scll(n);
	ll a[n], b[n];
	getchar();
	rep(i,0,n)
	{
		c=getchar();
		if(c=='L')
		b[i]=0;
		else
		b[i]=1;
	}
	rep(i,0,n)
	scll(a[i]);
	bool f=false;
	rep(i,0,n-1)
	{
		if(b[i]==1&&b[i+1]==0)
		{
			t=min(t,(a[i+1]-a[i])/2);
			f=true;
		}
	}
	if(f)
	prll(t);
	else
	prll(-1ll);
	return 0;
}
