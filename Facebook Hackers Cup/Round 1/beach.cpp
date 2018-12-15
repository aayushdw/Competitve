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
#define MAX 2000+5
using namespace std;

ll r[MAX],c[2*MAX],f[MAX];

void pre()
{
	f[0]=1;
	rep(i,1,MAX)
	{
		f[i]=i*f[i-1];
		f[i]%=MOD;
	}
}

ll powmod(ll a,ll b)
{
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x%MOD;
}

ll nCr(ll n,ll r)
{
	if(n<r)
		return 0;
	ll ret=1;
	rep(i,0,r)
	{
		ret*=(n-i);
		ret%=MOD;
	}
	ret*=powmod(f[r],MOD-2);
	ret%=MOD;
	//printf("%lldC%lld = %lld\n",n,r,ret);
	return ret;
}

int main()
{
	pre();
	ll t,n,m,sum,ans,p;
	sl(t);
	rep(tt,1,t+1)
	{
		sum=0; ans=0;
		sl(n); sl(m);
		rep(i,0,n)
		{
			sl(r[i]);
			sum+=2*r[i];
		}
		if(n==1)
		{
			ans=m;
			printf("Case #%lld: %lld\n",tt,ans);
			continue;
		}

		clr(c);
		rep(i,0,n)
		rep(j,i+1,n)
		c[r[i]+r[j]]++;

		rep(i,2,2*MAX)
		{
			if(!c[i])
				continue;
			p=nCr(m-sum+i+n-1,n);
			p*=f[n-2];
			p%=MOD;
			p*=2*c[i];
			p%=MOD;
			ans+=p;
			ans%=MOD;
		}
		printf("Case #%lld: %lld\n",tt,ans);
	}
	return 0;
}