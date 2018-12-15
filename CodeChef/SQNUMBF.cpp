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
#define MAX 1000000
typedef long long int ll;
using namespace std;
bitset<MAX> t;
ll primes[78500],coun;


int T;
ll mod;
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll a[]={1996011519951206ll,1995120619960115ll,1995100319960115ll,195100319951206ll,1996011519951003ll};
 
 
ll multi(ll x,ll y)
{
	ll w=x*y-mod*(ll(double(x)*y/mod+1e-3));
	while(w<0)
		w+=mod;
	while(w>=mod)
		w-=mod;
	return w;
}
 
ll pow(ll x,ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
			t=multi(t,x);
		x=multi(x,x);
		y>>=1;
	}
	return t;
}
 
bool judge(ll n)
{
	if(n==2) return true;
	if(n<2||!(n&1)) return false;
	for(int i=0;i<25;i++)
		if(n%b[i]==0&&n!=b[i])
			return false;
	mod=n;
	int t=0;
	ll u=n-1;
	while(!(u&1)) t++,u>>=1;
	for(int i=0;i<5;i++)
	{
		ll x=a[i]%(n-1)+1;
		x=pow(x,u);
		ll y=x;
		for(int j=1;j<=t;j++)
		{
			x=multi(x,x);
			if(x==1&&y!=1&&y!=n-1)
				return false;
			y=x;
		}
		if(x!=1) return false;
	}
	return true;
}
 

ll gcd ( ll a, ll b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

void seive()
{
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
	coun=j;
	return;
}

ll isSquare(ll p)
{
	double a=sqrt(p);
	ll q=(ll)a;
	if(q*q==p)
	return q;
	return 0;
}

int main()
{
	seive();
	ll t,n,i,j,p;
	scll(t);
	ll a[105]={0};
	while(t--)
	{
		scll(n);
		for(i=0;i<n;i++)
		{
			scll(a[i]);
		}
		ll ans=1;
		for(i=0;i<n;i++)
		for(j=0;j<i;j++)
		if(gcd(a[i],a[j])>1)
		{
			ans=gcd(a[i],a[j]);
		}
		if(ans>1)
		{
			printf("%lld\n",ans);
			continue;
		}
		ll f=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<coun && primes[j]*primes[j]<=a[i];j++)
			{
				p=primes[j];
				p*=p;
				if(a[i]%p==0)
				{
					f=1;
					ans=primes[j];
					break;
				}
				else if(a[i]%primes[j]==0)
				{
					a[i]/=primes[j];
				}
			}
			if(f)
			break;
			
		}
		if(f)
		{
			printf("%lld\n",ans);
			continue;
		}
		
		for(i=0;i<n;i++)
			{
				if(isSquare(a[i]))
				{
					p=isSquare(a[i]);
					if(judge(p))
					{
						ans=p;
						break;
					}
				}
			}
			printf("%lld\n",ans);
	}
}
