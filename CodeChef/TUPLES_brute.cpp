#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

vl v;
ll a[MAX],c,p;

int gcd(int n1,int n2)
{
	if(!n1 && !n2)
		return 0;
    else if(!n2)
       return n1;
	else if(!n1)
		return n2;
    else 
       return gcd(n2,n1%n2);
}

int main()
{
	ll t,n;
	sl(t);
	while(t--)
	{
		c=0;
		p=0;
		sl(n);
		rep(i,0,n)
		sl(a[i]);

		rep(i,0,n)
		rep(j,0,n)
		v.pb((a[i]*a[j])%359999);

		/*rep(i,0,v.size())
		printf("%lld ",v[i]);*/

		/*rep(i,0,v.size())
		rep(j,i+1,v.size())
		if(gcd(v[i],v[j])==1)
			p++;*/

		rep(i,0,v.size())
		rep(j,0,v.size())
		rep(k,0,v.size())
		if(gcd(v[i],gcd(v[j],v[k]))==1)
		{
			//printf("(%lld %lld %lld) = (%lld %lld %lld)\n",i,j,k,v[i],v[j],v[k]);
			c++;
		}

		//prll(p);
		prll(c);
	}
	return 0;
}