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

/*pair< pll , ll > foo(pair< pll , ll > a , pair< pll , ll > b)
{	return a<b?a:b;	}*/

ll isSquare(ll p)
{
	double x=sqrt(p);
	ll y=(ll)x;
	for(int i=y+2 ; i>y-3 ; i--)
	if(i*i==p)
		return i;
	return 0;
	//if(x*x==)
}

ll powmod(ll a,ll b,ll mod)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

ll sum(ll a,ll p)
{
	if(a==1)
		return p;

	ll inv=powmod(a-1,MOD-2,MOD);
	ll ret=powmod(a,p+1,MOD)-1;
	if(ret<0)	ret+=MOD;
	ret*=inv;
	ret%=MOD;
	return ret;
}

int main()
{
	ll t,x,y,z,l,r,a,b,c;
	sl(t);
	pair< pll , ll > tri;
	while(t--)
	{
		sl(x); sl(y); sl(z);
		sl(l); sl(r);
		bool flag=true;
		for(a=1 ; flag && a*a<x && a*a*a<y && a*a*a*a<z ; a++)
		{
			ll a2=a*a, a3=a2*a, a4=a3*a;
			for(b=a+1 ; a2+b*b<x && a3+b*b*b<y && a4+b*b*b*b<z; b++)
			{
				ll b2=b*b, b3=b2*b, b4=b3*b;
				ll c2=x-a2-b2;
				if(isSquare(c2)>0)
				{
					//printf("a=%lld b=%lld c=%lld\n",a,b,c);
					c=isSquare(c2);
					if(a3+b3+c*c*c==y && a4+b4+c*c*c*c==z && c>b)
					{
						tri=mp(mp(a,b),c);
						flag=false;
						break;
					}
				}
			}
		}
		//printf("%lld %lld %lld\n",tri.F.F,tri.F.S,tri.S);
		a=tri.F.F, b=tri.F.S, c=tri.S;

		//printf("a=%lld b=%lld c=%lld\n",a,b,c);

		ll ans=0,inv;

		ans+=sum(a,r); ans-=sum(a,l-1); ans%=MOD;
		if(ans<0) ans+=MOD;

		ans+=sum(b,r); ans-=sum(b,l-1); ans%=MOD;
		if(ans<0) ans+=MOD;

		ans+=sum(c,r); ans-=sum(c,l-1); ans%=MOD;
		if(ans<0) ans+=MOD;

		prll(ans);
	}
	return 0;
}