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
	ll n,c[4]={0},ans=0,p;
	scll(n);
	scll(p);
	if(p<4)
		c[p]++;
	scll(p);
	if(p<4)
		c[p]++;
	rep(i,2,n)
	{
		scll(p);
		if(p>3)
			ans+=((c[1]-1)*c[1])/2;
		else
		{
			if(p==1)
			{
				ans+=3*((c[1]-1)*c[1])/2;
				ans+=2*c[1]*c[2];
				ans+=(i-c[1]-c[2])*c[1];
				ans+=((c[2]-1)*c[2])/2;
			}
			if(p==2)
			{
				ans+=2*((c[1]-1)*c[1])/2;
				ans+=c[1]*c[3];
				ans+=c[1]*c[2];
			}
			if(p==3)
			{
				ans+=((c[1]-1)*c[1])/2;
				ans+=c[1]*c[2];
			}
			c[p]++;
		}
	}
	prll(ans);
	return 0;
}