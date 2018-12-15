#include<bits/stdc++.h>
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
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define MAX 100000000+200
using namespace std;
bitset<MAX> t;
ll primes[5761500],ct,pmult[5761500];;
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
	i=2;
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
		i++;
	}
	
	j=0;
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	ct=j;
	return;
}
ll modulo(ll a,ll b,ll MOD)
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
void init(ll mod)
{
	pmult[0]=primes[0];
	rep(i,1,ct)
	pmult[i]=(pmult[i-1]*primes[i])%mod;
}
ll bin_search(ll low,ll high,ll key)
{
	if(high==low)
		return low;
	if(high==low+1)
	{
		if(primes[high]>key)
			return low;
		else
			return high; 
	}
	ll mid=(high+low)/2;
	if(primes[mid]>key)
		return bin_search(low,mid,key);
	else
		return bin_search(mid,high,key);
}
ll solve(ll n,ll mod)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else if(n==3)
		return 6;
	ll m,mul,p,ans=1,i,j;
	for(i=0;primes[i]*primes[i]<=n;i++)
	{
		p=primes[i];
		m=n; mul=1;
		while(m>=p)
		{
			m/=p;
			mul*=p;
		}
		ans=(ans*mul)%mod;
	}
	i--;
	//printf("After 1: %lld\n",ans);
	j=bin_search(0,ct,n);
	p=pmult[j]*modulo(pmult[i],mod-2,mod); p%=mod;
	//printf("After 2: %lld\n",p);
	ans=(ans*p)%mod;
	return ans;
}
int main()
{
	seive();
	//return 0;
	ll t,mod,n,ans;
	scll(t); scll(mod);
	init(mod);
	while(t--)
	{
		scll(n);
		ans=solve(n,mod);
		printf("%lld\n",ans);
	}
	return 0;
}