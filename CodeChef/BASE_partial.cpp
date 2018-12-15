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
 
#define ROUNDOFFINT(d) d = (ll)((double)d + 0.5)
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
#define eps 1e-8
using namespace std;
 
void solve(ll n)
{
	if(n==1)
	{
		printf("INFINITY\n");
		return;
	}
	if(n==0)
	{
		printf("0\n");
		return;
	}
	ll k=2,ret=0,c,d;
	double a,b;
	while(1)
	{
		a=pow(n/2.0,1.0/(k-1));
		b=pow(n,1.0/(k-1));
		if(abs(a-ceil(a))<eps/n)
			a=ceil(a);
		else
			a=floor(a);
		if(abs(b-ceil(b))<eps)
			b=ceil(b);
		else
			b=floor(b);
		//printf("%0.9lf %0.9lf\n",a,b);
		c=ROUNDOFFINT(a); d=ROUNDOFFINT(b);
		if(d==1)
			break;
		ret+=d-c;
		k++;
		//printf("%lld %lld\n",c,d);
	}
	printf("%lld\n",ret);
}
 
int main()
{
	int t;
	ll n;
	sc(t);
	while(t--)
	{
		scll(n);
		//printf("%lld = ",n);
		solve(n);
	}
	return 0;
} 