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
#define MAX 100000+5
using namespace std;


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

ll foo(ll a,ll b)
{
	ll ret=powmod(2,a,MOD);
	ret+=MOD-1;
	ret%=MOD;
	ret*=b;
	ret%=MOD;
	return ret;
}

int main()
{
	string s;
	cin>>s;
	/*char c='a';
	bool f=false;
	ll p=0;
	vl v;
	rep(i,0,s.size())
	{
		if(s[i]=='a')
		{
			f=true;
			//p=1;
		}
		if(!f)
			continue;

		if(s[i]==c)
			p++;
		else
		{
			v.pb(p);
			if(c=='a')
				c='b';
			else
				c='a';
			p=1;
		}
	}
	ll ans=0;
	if(p)
	v.pb(p);
	for(int i=0;i+1<v.size();i+=2)
	{
		printf("%lld %lld\n",v[i],v[i+1]);
		ans+=foo(v[i],v[i+1]);
		ans%=MOD;
	}
	prll(ans);*/

	ll b=0,ans=0;
	reverse(all(s));
	rep(i,0,s.size())
	{
		if(s[i]=='a')
		{
			ans+=b;
			ans%=MOD;
			b*=2;
		}
		else
			b++;
		b%=MOD;
	}
	prll(ans);


	return 0;
}