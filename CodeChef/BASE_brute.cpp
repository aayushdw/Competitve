#include<bits/stdc++.h>

#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)

#define ll long long int
#define ull unsigned long long int
#define F first
#define S second

#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair

#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero

#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;
bool check(ll n,ll b)
{
	ll p;
	while(1)
	{
		p=n%b;
		n/=b;
		if(!n)
			return p==1;
	}
}
int main()
{
	ll t,n,c;
	scll(t);
	while(t--)
	{
		scll(n);
		//printf("%lld = ",n);
		if(n==1)
		{
			printf("INFINITY\n");
			continue;
		}
		c=0;
		for(ll i=2;i*i<=n;i++)
		if(check(n,i))
		{
			//printf("%d ",i);
			c++;
		}
		c+=(n+1)/2;
		prll(c);
	}
	return 0;
}