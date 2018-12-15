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
#define MAX 500000+5
using namespace std;

ll a[4],f[MAX],invf[MAX];

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
	f[0]=1;
	f[1]=1;
	rep(i,2,MAX)
	{
		f[i]=f[i-1]*i;
		f[i]%=MOD;
	}
	rep(i,0,MAX)
		invf[i]=powmod(f[i],MOD-2,MOD);
}

int main()
{
	pre();
	
	int t;
	ll temp1,temp2;
	si(t);
	string s;
	ll ans1,ans2,ans;
	while(t--)
	{
		clr(a);
		cin>>s;
		rep(i,0,s.length())
		a[s[i]-'a']++;
		ans1=1;
		ans2=1;

		//printf("%lld %lld %lld %lld\n",a[0],a[1],a[2],a[3]);

		rep(x,1,min(a[0],a[1])+1)
		{
			temp1=f[a[0]];
			temp1*=invf[a[0]-x];
			temp1%=MOD;
			temp1*=invf[x];
			temp1%=MOD;

			//prll(invf[x]);

			temp2=f[a[1]];
			temp2*=invf[a[1]-x];
			temp2%=MOD;
			temp2*=invf[x];
			temp2%=MOD;

			temp2*=temp1;
			temp2%=MOD;

			ans1+=temp2;
			ans1%=MOD;
		}

		rep(x,1,min(a[2],a[3])+1)
		{
			temp1=f[a[2]];
			temp1*=invf[a[2]-x];
			temp1%=MOD;
			temp1*=invf[x];
			temp1%=MOD;

			temp2=f[a[3]];
			temp2*=invf[a[3]-x];
			temp2%=MOD;
			temp2*=invf[x];
			temp2%=MOD;

			temp2*=temp1;
			temp2%=MOD;

			ans2+=temp2;
			ans2%=MOD;
		}

		ans=(ans1*ans2)+MOD-1;
		ans%=MOD;
		prll(ans);
	}
	return 0;
}