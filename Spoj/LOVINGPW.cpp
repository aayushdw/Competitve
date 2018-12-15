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
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bool power(ll n)
{
	ll num=1;
	while(num<=n)
	{
		if(num==n)
			return true;
		num*=2;
	}
	return false;
}
int main()
{
	ll t,n,c;
	scll(t);
	while(t--)
	{
		scll(n); c=0;
		rep(i,0,n+1)
		rep(j,0,i)
		{
			if(power(i^j))
			{
				c++;
				printf("%lld %lld\n",i,j);
			}
		}
		printf("%lld\n",c);
	}
	return 0;
}