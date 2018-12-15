#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
int main()
{
	ll n;
	scll(n);
	ll a[n],b[n],l=0,r=0,k;
	rep(i,0,n)
	{
		scll(a[i]); scll(b[i]);
		l+=a[i]; r+=b[i];
	}
	ll p=l-r;
	ll ans=abs(p),m=-1;
	//printf("%lld\n",p);
	rep(i,0,n)
	{
		k=abs(p+2*(b[i]-a[i]));
		//printf("%lld\n",k);
		if(k>ans)
			ans=k, m=i+1;
	}
	if(m==-1)
		m=0;
	prll(m);
	return 0;
}