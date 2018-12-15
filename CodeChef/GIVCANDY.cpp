#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	ll t,a,b,c,d,p,q,x,ans;
	scll(t);
	while(t--)
	{
		scll(a); scll(b); scll(c); scll(d);
		p=gcd(c,d);
		q=a>b?a-b:b-a;
		x=q/p;
		ans=min(x*p-q,q-(x+1)*p);
		printf("%lld\n",ans);
	}
	return 0;
}
