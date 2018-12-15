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
#define MAX 100000+5

using namespace std;

vi v;

#define MAXSIEVE 100000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 160 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

void seive()
{
	int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
	if (a[i>>3]&(1<<(i&7)))
	for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
	a[j>>3]&=~(1<<(j&7));
}

//For one Value of phi
int phi(int n)
{
  int result=n,i;
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    result-=result/i;
    while(n%i==0)
    n/=i;
  }
  if(n>1)
  result-=result/n;
  return result;
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

bool check(int x,int p)
{
	p--;
	rep(i,0,v.size())
	if(powmod(x,p/v[i],p+1)==1)
		return false;
	return true;
}

int main()
{
	seive();
	int p;
	si(p);
	int b=phi(phi(p));
	int x=p-1;


	if(!(x%2))
	{
		v.pb(2);
		while(!(x%2))
			x/=2;
	}

	for(int i=3;i*i<=x;i+=2)
	if(isprime(i) && !(x%i))
	{
		v.pb(i);
		while(!(x%i))
			x/=i;
	}

	if(x!=1)
		v.pb(x);

	for(int i=2;;i++)
	if(check(i,p))
	{
		printf("%d %d",i,b);
		return 0;
	}
}