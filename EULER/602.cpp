#include <bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
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
#define priority_queue pq;
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
#define MAX 10000
#define PI acos(-1.0)
using namespace std;

long double fun(long double x, long double y)
{
	return  ( PI/2 + atan((3-y)/x) + atan((4-x)/y) ) / (2*PI);
}

long double getFloat()
{
	ll x = rand()%MAX;
	ll y = rand()%MAX;
	if(x>y)	swap(x,y);
	long double ret = x*1.0/y;
	return ret;
}

int main()
{
	srand(time(NULL));
	ll iter = 1000000000;
	ll p = iter;
	long double ans = 0;
	while(iter--)
	{
		long double x = getFloat();
		long double y = getFloat();
		long double val = fun(x,y);
		if(isnan(val)) p--;
		else ans+=val;
		//printf("%0.9Lf %0.9Lf %0.9Lf\n",x,y,val);
	}
	printf("%0.15Lf\n",ans/p);
	return 0;
}