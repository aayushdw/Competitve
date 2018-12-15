#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 60
using namespace std;

bitset<MAX> a,b,c;

int main()
{
	ll x,y,ans=0;
	sl(x); sl(y);
	rep(i,0,60)
	a[i]=ison(x,59-i);
	rep(i,0,60)
	b[i]=ison(y,59-i);
	
	c.reset();
	bool f=false;
	rep(i,0,60)
	{	
		if(!a[i] && b[i])
		f=true;
		
		c[i]=a[i]^b[i];
		
		if(f)
		{
			if(!a[i] && !b[i])
			c[i]=true;
			if(a[i] && b[i])
			c[i]=true;
		}
	}
	
	/*rep(i,0,60)
	if(a[i])
		printf("1");
	else
		printf("0");
	printf("\n");
		
	rep(i,0,60)
	if(b[i])
		printf("1");
	else
		printf("0");
	printf("\n");
		
	rep(i,0,60)
	if(c[i])
		printf("1");
	else
		printf("0");
	printf("\n");*/
	
	for(int i=59,k=0; i>=0 ; i--,k++)
	ans+=c[i]*(1ll<<k);
	
	prll(ans);
	
	return 0;
}
