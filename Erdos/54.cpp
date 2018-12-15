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
#define MAX 100
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bool isSquare(ll p)
{
	double a=sqrt(p);
	ll q=(int)a;
	if(q*q==p)
	return true;
	return false;
}
int main()
{
	ll p,ans=-1;
	rep(a,1,MAX)
	rep(b,a,MAX)
	rep(c,b,MAX)
	rep(d,c,MAX)
	rep(e,d,MAX)
	{
		p=a*a+b*b+c*c+d*d+e*e;
		if(isSquare(p))
		{
			//printf("%lld %lld %lld %lld %lld %lld\n",a,b,c,d,e,p);
			p=(ll)(sqrt(p));
			if(ans==-1)
				ans=a*b*c*d*e*p;
			else
				ans=__gcd(ans,a*b*c*d*e*p);
		}
	}
	prll(ans);
	return 0;
}