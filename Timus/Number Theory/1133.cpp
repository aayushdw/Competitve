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
#define MAX 2000000000
using namespace std;

ll fib[2005]={0,1};

void pre()
{
	rep(i,2,2005)
	if(fib[i-1]+fib[i-2]<MAX)
		fib[i]=fib[i-1]+fib[i-2];
	else
		fib[i]=MAX+1;
	return;
}

int main()
{
	pre();
	ll x,fx,y,fy,n,z,p,q,ans;
	sl(x); sl(fx); sl(y); sl(fy); sl(n);
	if(y<x)
		swap(x,y), swap(fx,fy);
	z=y-x;
	//prll(z);
	z=(fy-fib[z+1]*fx)/fib[z];
	if(n>=x)
	{
		n-=x;
		ans=fib[n+1]*fx+fib[n]*z;
	}
	else
	{
		n=x-n-1;
		if(n%2)
			ans=fib[n]*fx-fib[n+1]*z;
		else
			ans=-fib[n]*fx+fib[n+1]*z;
	}
	prll(ans);
	return 0;
}