#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define MAX 100+5
typedef long long int ll;
using namespace std;
bitset<MAX> t;
ll primes[30],ct;
void seive()
{
	t.reset();
	t[0]=true; t[1]=true; t[2]=false;
	
	ll i=2,j;
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
			j++;
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

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
    {
        printf("ERROR");
		return -1;
	}
    else
    {
        // m is added to handle negative x
        ll res = (x%m + m) % m;
        return res;
    }
}

ll mulmod(ll x, ll y, ll m) {
    ll w=x*y-m*(ll(double(x)*y/m+1e-3));
	while(w<0)
		w+=m;
	while(w>=m)
		w-=m;
	return w;
}

int main()
{
	seive();
	ll num=13082761331670030,x=num,i=0,p,n=1,y,ans;
	vector<ll> v,s;
	v.pb(1);
	while(x>1)
	{
		if(x%primes[i]!=0)
		{
			i++;
			continue;
		}
		p=primes[i++];
		x/=p;
		rep(j,0,p-1)
		{
			if((j*j*j)%p==1)
			{
				printf("%lld %lld\n",j,p);
				rep(k,0,v.size())
				{
					y=v[k];
					ll MOD=p*n;
					ans=mulmod(mulmod(j,n,MOD),modInverse(n,p),MOD);
					ans+=mulmod(mulmod(y,p,MOD),modInverse(p,n),MOD);
					ans%=MOD;
					//printf("%lld ",ans);
					s.pb(ans);
				}
			}
		}
		//rep(j,0,s.size())
		printf("%lld\n",s.size());
		if(!s.empty())
		{
			v.clear();
			v.insert(v.begin(),s.begin(),s.end());
			s.clear();
		}
		n*=p;
	}
	ll sum=0;
	rep(i,1,v.size())
	sum+=v[i];
	printf("%lld ",sum);
}
