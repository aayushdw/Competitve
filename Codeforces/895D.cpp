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
#define MAX 1000000+5
using namespace std;

ll f[MAX]={1},invf[MAX]={1};

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

void pre()
{
	rep(i,1,MAX)
	{
		f[i] = f[i-1]*i;
		f[i] %= MOD;
		invf[i] = invf[i-1]*powmod(i,MOD-2,MOD);
		invf[i] %= MOD;
	}
	return;
}

ll getrank(string &s)
{
	int c[26],d[26];
	clr(c); clr(d);
	rep(i,0,s.size())
		c[s[i]-'a']++;
	ll ret = 0;
	rep(i,0,s.size())
	{
		c[s[i]-'a']--;
		//d[s[i]-'a']++;
		ll p = 0;
		rep(j,s[i]-'a'+1,26) //CHECK
			p += c[s[i]-'a'];

		rep(j,s[i]-'a'+1,26)
		{
			ll temp = f[p];
			
		}

		ll k = c[s[i]-'a'];
		ll temp = f[p];
		temp *= invf[k];
		temp %= MOD;
		ret += temp;
		ret %= MOD;
	}
	return ret;
}

int main()
{
	pre();
	int n;
	string s,t;
	//cin>>s>>t;
	cin>>s;
	ll x = getrank(s);
	//ll y = getrank(t);
	//ll ans = (y-x+MOD)%MOD;
	prll(x);
	return 0;
}