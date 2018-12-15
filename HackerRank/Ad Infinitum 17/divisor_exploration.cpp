#include<bits/stdc++.h>

#define si(x) scanf("%d",&x)
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
#define MAX 1400000
#define MAXSZ 110000+5

using namespace std;

bitset<MAX> t;
ll primes[MAXSZ],ct;

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

void seive()
{
	t.reset();
	t[0]=true; t[1]=true; t[2]=false;
	
	ll i=2,j;
	while(i*2<MAX)
	{
		t[i*2]=1;
		i++;
	}
	i=3;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j+=2;
		}
		i+=2;
	}
	
	j=0;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	
	ct=j;
	return;
}


ll foo(ll p, ll a)
{
	p=primes[p];
	ll inv=powmod(p-1,MOD-2,MOD);
	ll ret=powmod(p,a+2,MOD)-1;
	if(ret<0)
		ret+=MOD;
	ret*=inv;
	ret%=MOD;
	ret-=a+2;
	if(ret<0)
		ret+=MOD;
	ret*=inv;
	ret%=MOD;
	return ret;
}

ll solve(ll m, ll a)
{
	ll ret=1;
	rep(i,0,m)
	{
		ret*=foo(i,a+i+1);
		ret%=MOD;
	}
	return ret;
}

int main()
{
	seive();
	int t;
	ll m,a;
	si(t);
	while(t--)
	{
		sl(m); sl(a);
		prll(solve(m,a));
	}
	return 0;
}