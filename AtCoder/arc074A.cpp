#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define MAX 100000+5
using namespace std;

ll solve(ll h,ll w)
{
	ll ret=INF;
	if(w>=3)
		ret=(w%3)?h:0;
	//printf("%lld %lld\n",h,w);
	rep(i,1,w)
	{
		ll x=i*h,y=0,z=0;
		if(h%2)
		{
			y=(h/2)*(w-i);
			z=(h/2+1)*(w-i);
			ret=min(ret , max( abs(x-y) , max( abs(y-z) , abs(x-z) ) ));
		}
		else
		{
			y=(h/2)*(w-i);
			ret=min(ret,abs(x-y));
		}
		//printf("%lld %lld %lld %lld\n",i,x,y,z);
	}
	return ret;
}

int main()
{
	ll h,w;
	sl(h); sl(w);
	prll(min(solve(h,w),solve(w,h)));
	return 0;
}